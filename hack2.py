from math import sqrt; from itertools import count, islice
N = int(raw_input())
M = int(raw_input())

g = [[0 for i in xrange(M)] for i in xrange(N)]

curr_pos = [0,0]
path_sofar = [[0,0]]
paths = []

for i in xrange(N):
    nums = raw_input().split(' ')
    for j in xrange(M):
        g[i][j] = int(nums[j])
#print g

def next_move(pos):
    n_pos = []
    if pos[0]+1 <= N-1:
        n_pos.append([pos[0]+1,pos[1]])
    if pos[1]+1 <= M-1:
        n_pos.append([pos[0],pos[1]+1])
    if (pos[1]+1 <= M-1 and pos[0]+1 <= N-1):
        n_pos.append([pos[0]+1,pos[1]+1])
    return n_pos

def valid_move(pos):
    return is_prime(g[pos[0]][pos[1]])

def is_prime(n):
    return n > 1 and all(n%i for i in islice(count(2), int(sqrt(n)-1)))

def path_finder(curr):
    if curr == [N-1,M-1]:
        path_sofar.append(curr)
        paths.append(path_sofar)
        #print paths
    else:
        n_mv = next_move(curr)
        mv = [True for i in range(len(n_mv))]

        for i in range(len(n_mv)):
            if valid_move(n_mv[i]):
                path_sofar.append(n_mv[i])
                path_finder(n_mv[i])
                del path_sofar[-1]
            else:
                mv[i] = False
        if(not any(mv)):
            return

path_finder([0,0])

print len(paths)
print paths
