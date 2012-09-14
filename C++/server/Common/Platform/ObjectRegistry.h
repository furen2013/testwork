#ifndef OBJECTREGISTRY_H
#define OBJECTREGISTRY_H

#include "Define.h"
#include "../Utilities/HashMap.h"
#include "Singleton.h"

#include <string>
#include <map>

/** ObjectRegistry holds all registry item of the same type
 */
template<class T, class Key = std::string>
class SUNYOU_DLL_DECL ObjectRegistry
{
    typedef std::map<Key, T *> RegistryMapType;
    RegistryMapType i_registeredObjects;
    friend class SUNYOU::OperatorNew<ObjectRegistry<T, Key> >;

    // protected for friend use since it should be a singleton
    ObjectRegistry() {}
    ~ObjectRegistry()
    {
        for(typename RegistryMapType::iterator iter=i_registeredObjects.begin(); iter != i_registeredObjects.end(); ++iter)
            delete iter->second;
        i_registeredObjects.clear();
    }

    public:

        /// Returns a registry item
        const T* GetRegistryItem(Key key) const
        {
            typename RegistryMapType::const_iterator iter = i_registeredObjects.find(key);
            return( iter == i_registeredObjects.end() ? NULL : iter->second );
        }

        /// Inserts a registry item
        bool InsertItem(T *obj, Key key, bool override = false)
        {
            typename RegistryMapType::iterator iter = i_registeredObjects.find(key);
            if( iter != i_registeredObjects.end() )
            {
                if( !override )
                    return false;
                delete iter->second;
                i_registeredObjects.erase(iter);
            }

            i_registeredObjects[key] = obj;
            return true;
        }

        /// Removes a registry item
        void RemoveItem(Key key, bool delete_object = true)
        {
            typename RegistryMapType::iterator iter = i_registeredObjects.find(key);
            if( iter != i_registeredObjects.end() )
            {
                if( delete_object )
                    delete iter->second;
                i_registeredObjects.erase(iter);
            }
        }

        /// Returns true if registry contains an item
        bool HasItem(Key key) const
        {
            return (i_registeredObjects.find(key) != i_registeredObjects.end());
        }

        /// Return a list of registered items
        unsigned int GetRegisteredItems(std::vector<Key> &l) const
        {
            unsigned int sz = l.size();
            l.resize(sz + i_registeredObjects.size());
            for(typename RegistryMapType::const_iterator iter = i_registeredObjects.begin(); iter != i_registeredObjects.end(); ++iter)
                l[sz++] = iter->first;
            return i_registeredObjects.size();
        }
};
#endif
