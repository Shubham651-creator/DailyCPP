-------------------------------------------------------------------
# CPU : Central Processing Unit

[Processor] : Hardware to execute instructions.

[Instructions] : Commands to perform some action on the hardware.

[Core_count] : Number of worker nodes in a processor.

[Clock_speed](Hz):
- 2.3GHz i.e. 2.3G instructions per second.

----------------------------------------------------------------------

# Hyer Threading :
- The ability to run muliple threads on single processor(core).

----------------------------------------------------------------------

# Critical Section :
- It is code of block which can access shared memory.

    > std::mutex mt;
    > mt.lock();
    > mt.unlock();

----------------------------------------------------------------------

# Type of delay:

    1. i/o delay
    - input : 
    - output ; screen,etc.

    2. CPU bound task delay
    - cpu operation : register, ALU 