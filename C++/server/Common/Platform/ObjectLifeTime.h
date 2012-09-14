#ifndef SUNYOU_OBJECTLIFETIME_H
#define SUNYOU_OBJECTLIFETIME_H
#if 0
#include <stdexcept>

typedef void (* Destroyer)(void);

namespace SUNYOU
{
    void at_exit( void (*func)() );

    template <class T>
        class ObjectLifeTime
    {
        public:
            inline static void ScheduleCall(void (*destroyer)() )
            {
                at_exit( destroyer );
            }

            static void OnDeadReference(void) ATTR_NORETURN;

    };

    template <class T>
        inline void ObjectLifeTime<T>::OnDeadReference(void)// We don't handle Dead Reference for now
    {
        throw std::runtime_error("Dead Reference");
    }
}
#endif
#endif
