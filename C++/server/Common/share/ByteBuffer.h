#ifndef _BYTEBUFFER_H
#define _BYTEBUFFER_H

#include "TypeDef.h"
#include "assert.h"
#include "PacketDef.h"
class ByteBuffer
{
    public:
        const static size_t DEFAULT_SIZE = 0x1000;

        // constructor
        ByteBuffer(): _rpos(0), _wpos(0)
        {
            _storage.reserve(DEFAULT_SIZE);
        }
        // constructor
        ByteBuffer(size_t res): _rpos(0), _wpos(0)
        {
            _storage.reserve(res);
        }
        // copy constructor
        ByteBuffer(const ByteBuffer &buf): _rpos(buf._rpos), _wpos(buf._wpos), _storage(buf._storage) { }

		CPacketSn& Sn(CPacketSn& cps) const {	cps<< (const unsigned int)size();cps.AddBuf(contents(), size()); return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	size_t count;cpu>>count;resize(count);cpu.GetBuf((void*)contents(),(ui32)count); return cpu; }

        inline void clear()
        {
            _storage.clear();
            _rpos = _wpos = 0;
        }

        template <typename T> void append(T value)
        {
            append((ui8 *)&value, sizeof(value));
        }
        template <typename T> void put(size_t pos,T value)
        {
            put(pos,(ui8 *)&value,sizeof(value));
        }

        inline ByteBuffer &operator<<(bool value)
        {
            append<char>((char)value);
            return *this;
        }
        inline ByteBuffer &operator<<(ui8 value)
        {
            append<ui8>(value);
            return *this;
        }
        inline ByteBuffer &operator<<(ui16 value)
        {
            append<ui16>(value);
            return *this;
        }
        inline ByteBuffer &operator<<(ui32 value)
        {
            append<ui32>(value);
            return *this;
        }
        inline ByteBuffer &operator<<(ui64 value)
        {
            append<ui64>(value);
            return *this;
        }

        // signed as in 2e complement
        inline ByteBuffer &operator<<(i8 value)
        {
            append<i8>(value);
            return *this;
        }
        inline ByteBuffer &operator<<(i16 value)
        {
            append<i16>(value);
            return *this;
        }
        inline ByteBuffer &operator<<(i32 value)
        {
            append<i32>(value);
            return *this;
        }
        inline ByteBuffer &operator<<(i64 value)
        {
            append<i64>(value);
            return *this;
        }

        // floating points
        inline ByteBuffer &operator<<(float value)
        {
            append<float>(value);
            return *this;
        }
        inline ByteBuffer &operator<<(double value)
        {
            append<double>(value);
            return *this;
        }
        inline ByteBuffer &operator<<(const std::string &value)
        {
			//append<ui32>(value.length());
            append((ui8 const *)value.c_str(), value.length());
            append((ui8)0);
            return *this;
        }
        inline ByteBuffer &operator<<(const char *str)
        {
            append((ui8 const *)str, str ? strlen(str) : 0);
            append((ui8)0);
            return *this;
        }

        inline ByteBuffer &operator>>(bool &value)
        {
            value = read<char>() > 0 ? true : false;
            return *this;
        }
        inline ByteBuffer &operator>>(ui8 &value)
        {
            value = read<ui8>();
            return *this;
        }
        inline ByteBuffer &operator>>(ui16 &value)
        {
            value = read<ui16>();
            return *this;
        }
        inline ByteBuffer &operator>>(ui32 &value)
        {
            value = read<ui32>();
            return *this;
        }
        inline ByteBuffer &operator>>(ui64 &value)
        {
            value = read<ui64>();
            return *this;
        }

        //signed as in 2e complement
        inline ByteBuffer &operator>>(i8 &value)
        {
            value = read<i8>();
            return *this;
        }
        inline ByteBuffer &operator>>(i16 &value)
        {
            value = read<i16>();
            return *this;
        }
        inline ByteBuffer &operator>>(i32 &value)
        {
            value = read<i32>();
            return *this;
        }
        inline ByteBuffer &operator>>(i64 &value)
        {
            value = read<i64>();
            return *this;
        }

        inline ByteBuffer &operator>>(float &value)
        {
            value = read<float>();
            return *this;
        }
        inline ByteBuffer &operator>>(double &value)
        {
            value = read<double>();
            return *this;
        }
        inline ByteBuffer &operator>>(std::string& value)
        {
            value.clear();
            while (rpos() < size())                         // prevent crash at wrong string format in packet
            {
                char c=read<char>();
                if (c==0)
                    break;
                value+=c;
            }
            return *this;
        }

        inline ui8 operator[](size_t pos)
        {
            return read<ui8>(pos);
        }

        inline size_t rpos()
        {
            return _rpos;
        };

        inline size_t rpos(size_t rpos_)
        {
            _rpos = rpos_;
            return _rpos;
        };

        inline size_t wpos()
        {
            return _wpos;
        }

        inline size_t wpos(size_t wpos_)
        {
            _wpos = wpos_;
            return _wpos;
        }

        template <typename T> T read()
        {
            T r=read<T>(_rpos);
            _rpos += sizeof(T);
            return r;
        };
        template <typename T> T read(size_t pos) const
        {
            assert(pos + sizeof(T) <= size() || PrintPosError(false,pos,sizeof(T)));
            return *((T const*)&_storage[pos]);
        }

        inline void read(ui8 *dest, size_t len)
        {
            assert(_rpos  + len  <= size() || PrintPosError(false,_rpos,len));
            memcpy(dest, &_storage[_rpos], len);
            _rpos += len;
        }

        inline const ui8 *contents() const { return &_storage[0]; }

        inline size_t size() const { return _storage.size(); }
        inline bool empty() const { return _storage.empty(); }

        inline void resize(size_t newsize)
        {
            _storage.resize(newsize);
            _rpos = 0;
            _wpos = size();
        };
        inline void reserve(size_t ressize)
        {
            if (ressize > size()) _storage.reserve(ressize);
        };

        inline void append(const std::string& str)
        {
            append((ui8 const*)str.c_str(),str.size() + 1);
        }
        inline void append(const char *src, size_t cnt)
        {
            return append((const ui8 *)src, cnt);
        }
        template<class T>
        void append(const T *src, size_t cnt)
        {
            return append((const ui8 *)src, cnt*sizeof(T));
        }
        inline void append(const ui8 *src, size_t cnt)
        {
            if (!cnt) return;

            assert(size() < 10000000);

            if (_storage.size() < _wpos + cnt)
                _storage.resize(_wpos + cnt);
            memcpy(&_storage[_wpos], src, cnt);
            _wpos += cnt;
        }
        inline void append(const ByteBuffer& buffer)
        {
            if(buffer.size()) append(buffer.contents(),buffer.size());
        }

        inline void appendPackGUID(ui64 guid)
        {
            size_t mask_position = wpos();
            *this << ui8(0);
            for(ui8 i = 0; i < 8; i++)
            {
                if(guid & 0xFF)
                {
                    _storage[mask_position] |= (1<<i);
                    *this << ((ui8)(guid & 0xFF));
                }

                guid >>= 8;
            }
        }

        inline void put(size_t pos, const ui8 *src, size_t cnt)
        {
            assert(pos + cnt <= size() || PrintPosError(true,pos,cnt));
            memcpy(&_storage[pos], src, cnt);
        }
#ifdef SERVER_BUILD
#include "../../Server/Common/Platform/log.h"
        void print_storage()
        {
            if(!sLog.IsOutDebug())                          // optimize disabled debug output
                return;

            MyLog::log->debug("STORAGE_SIZE: %u", size() );
            for(ui32 i = 0; i < size(); i++)
                sLog.outDebugInLine("%u - ", read<ui8>(i) );
            MyLog::log->debug(" ");
        }

        void textlike()
        {
            if(!sLog.IsOutDebug())                          // optimize disabled debug output
                return;

            MyLog::log->debug("STORAGE_SIZE: %u", size() );
            for(ui32 i = 0; i < size(); i++)
                sLog.outDebugInLine("%c", read<ui8>(i) );
            MyLog::log->debug(" ");
        }

        void hexlike()
        {
            if(!sLog.IsOutDebug())                          // optimize disabled debug output
                return;

            ui32 j = 1, k = 1;
            MyLog::log->debug("STORAGE_SIZE: %u", size() );

            if(sLog.IsIncludeTime())
                sLog.outDebugInLine("         ");

            for(ui32 i = 0; i < size(); i++)
            {
                if ((i == (j*8)) && ((i != (k*16))))
                {
                    if (read<ui8>(i) < 0x0F)
                    {
                        sLog.outDebugInLine("| 0%X ", read<ui8>(i) );
                    }
                    else
                    {
                        sLog.outDebugInLine("| %X ", read<ui8>(i) );
                    }
                    ++j;
                }
                else if (i == (k*16))
                {
                    if (read<ui8>(i) < 0x0F)
                    {
                        sLog.outDebugInLine("\n");
                        if(sLog.IsIncludeTime())
                            sLog.outDebugInLine("         ");

                        sLog.outDebugInLine("0%X ", read<ui8>(i) );
                    }
                    else
                    {
                        sLog.outDebugInLine("\n");
                        if(sLog.IsIncludeTime())
                            sLog.outDebugInLine("         ");

                        sLog.outDebugInLine("%X ", read<ui8>(i) );
                    }

                    ++k;
                    ++j;
                }
                else
                {
                    if (read<ui8>(i) < 0x0F)
                    {
                        sLog.outDebugInLine("0%X ", read<ui8>(i) );
                    }
                    else
                    {
                        sLog.outDebugInLine("%X ", read<ui8>(i) );
                    }
                }
            }
            sLog.outDebugInLine("\n");
        }

    protected:
        bool PrintPosError(bool add, size_t pos, size_t esize) const
        {
            MyLog::log->error("ERROR: Attempt %s in ByteBuffer (pos: %u size: %u) value with size: %u",(add ? "put" : "get"),pos, size(), esize);

            // assert must fail after function call
            return false;
        }
#else
		inline bool PrintPosError(bool add, size_t pos, size_t esize) const
		{
			return false;
		}
#endif

        size_t _rpos, _wpos;
        std::vector<ui8> _storage;
};

template <typename T> ByteBuffer &operator<<(ByteBuffer &b, std::vector<T> v)
{
    b << (ui32)v.size();
    for (typename std::vector<T>::iterator i = v.begin(); i != v.end(); i++)
    {
        b << *i;
    }
    return b;
}

template <typename T> ByteBuffer &operator>>(ByteBuffer &b, std::vector<T> &v)
{
    ui32 vsize;
    b >> vsize;
    v.clear();
    while(vsize--)
    {
        T t;
        b >> t;
        v.push_back(t);
    }
    return b;
}

template <typename T> ByteBuffer &operator<<(ByteBuffer &b, std::list<T> v)
{
    b << (ui32)v.size();
    for (typename std::list<T>::iterator i = v.begin(); i != v.end(); i++)
    {
        b << *i;
    }
    return b;
}

template <typename T> ByteBuffer &operator>>(ByteBuffer &b, std::list<T> &v)
{
    ui32 vsize;
    b >> vsize;
    v.clear();
    while(vsize--)
    {
        T t;
        b >> t;
        v.push_back(t);
    }
    return b;
}

template <typename K, typename V> ByteBuffer &operator<<(ByteBuffer &b, std::map<K, V> &m)
{
    b << (ui32)m.size();
    for (typename std::map<K, V>::iterator i = m.begin(); i != m.end(); i++)
    {
        b << i->first << i->second;
    }
    return b;
}

template <typename K, typename V> ByteBuffer &operator>>(ByteBuffer &b, std::map<K, V> &m)
{
    ui32 msize;
    b >> msize;
    m.clear();
    while(msize--)
    {
        K k;
        V v;
        b >> k >> v;
        m.insert(make_pair(k, v));
    }
    return b;
}
#endif
