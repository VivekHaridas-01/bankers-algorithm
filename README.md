# bankers-algorithm
Implementation of Banker’s Algorithm for Deadlock Avoidance.
## Implementation Details
We take n as the number of Processes and m as the number of Resources.
There are four types of data structures used to implement Banker’s algorithm.
1. Allocation Matrix (n*m)
2. Max Matrix (n*m)
3. Available Vector (1*m)
4. Need Matrix (n*m)

#### Allocation Matrix
- Allocation Matrix is a 2D array, of size ‘n*m’.
- It is used to define the number of resources of each kind presently assigned to each process.
- Allocation[i, j] = k indicates that the current process ‘Pi’ is assigned ‘k’ instances of ‘Rj’ resource type.
#### Max Matrix
- Max Matrix is a 2D array of size ‘n*m’.
- It is used to determine the maximum number of resources that each process requests.
- Max[i, j] = k indicates that ‘Pi’ can demand or request maximum ‘k’ instances of ‘Rj’ resource type.
#### Available Vector
- Available is a 1D array of size ‘m’.
- It is used to determine the number of available resources of each kind.
- Available[j] = k indicates that we have ‘k’ instances of ‘Rj’ resource type.
#### Need Matrix
- Need is a 2D array of size ‘n*m’.
- It is used to define the remaining resources which are required for each process.
- Need [i, j] = k indicates that for the execution of process, ‘Pi’, presently ‘k’ instances of resource type ‘Rj’ are required.
<p align="center">
    <b>Need [i,j] = Max [i,j] – Allocation [i,j]<b>
</p>
## Algorithm
Banker’s algorithm comprises of two algorithms:
1. Safety algorithm
2. Resource request algorithm

#### Safety Algorithm
1. Let Work and Finish be vectors of length m and n, respectively. <br> 
    Initialize:<br> 
        Work = Available
        Finish [i] = false for I = 0, 1, ..., n-1 <br>        
2. Find an į such that both: <br> 
a. Finish [i] = false <br> 
b. Need<sub>i</sub> <= Work <br> 
If no such i exists, go to step 4. <br>
3. Work = Work + Allocation<sub>i</sub> <br>
Finish[i] = true <br>
Go to step 2. <br>
4. If Finish [i] == true for all i, then the system is in a safe state. <br>
