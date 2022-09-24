from math import ceil

def solution(n, stations, w):
    n_stn = 0
    d = 2 * w + 1
    pos = 1
    
    rcvd = []
    
    for stn in stations:
        left = max(1, stn - w)
        right = min(n, stn + w)
        rcvd.append((left, right))
    
    rcvd.append((n + 1, n + 1))
    for left, right in rcvd:
        l = left - pos
        n_stn += 1 if 0 < l < d else ceil(l / d)
        pos = right + 1
        
    return n_stn
