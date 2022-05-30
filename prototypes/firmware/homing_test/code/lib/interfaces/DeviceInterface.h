
#ifndef ROBOX_CONTROLLER_INTERFACE_DEVICE_H
#define ROBOX_CONTROLLER_INTERFACE_DEVICE_H

namespace Interface 
{
    class IDevice 
    {
        public:
            virtual void Start() = 0;
            virtual void Run() = 0;
    };
}

#endif // ROBOX_CONTROLLER_BASE_DEVICE_H