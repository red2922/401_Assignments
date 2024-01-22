/*HW 5 CYBR 401 Create buffer, structures, grabbing memeory,have a timer, working with memeory, aquire and release, do
certain processes, run simulation until buffer is empty, bunch of structures, process structure, process num, size, time,
generate a size/time depending on a value

create memory area
create process from that memory process. Have a base and bound
Build a memory area and manage how, when , and where process goes. Don't mess with functions. run function does the labor
Grab current time stamp and then you will get a random value that allows you to do specific things.

Run process
create processes
grab resources
run through all the processes
make sure you go through all the processes in the buffer

Make processes
create processes
random number for the time and size
return the process
(No program can have a size or time of zero)

Print process
takes process
prints the Number
size
time

Memory function
is empty  -> checks wheather the structure is empty or not

Aquire task/memory
get Memory via index
check if there is space available
fill if there is space
otherwise throw error that there is not enough space/release the process

clear task/Memory
if process timed out or has completed clear the memory area and free it in the buffer.
find the index. find the start and end of the memory area.
clear process memory and move all process under it up into the newly freed process
Like a queue.

CAN ADD ADDITIONAL HELPED FUNCTION

Memory area
start
end
process


Make Buffer
return an array of memory area

Don't change main or run methods

size * sizeof memory area.
*/
