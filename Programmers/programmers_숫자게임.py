def lower_bound(arr, target):
    left = 0
    right = len(arr)
    while(left < right):
        mid = (left + right) // 2
        if target < arr[mid]:
            right = mid
        else:
            left = mid + 1
    return left

def solution(A, B):
    answer = 0
    B.sort() a

    for a in A:
        lb = lower_bound(B, a)
        if len(B) > lb:
            answer += 1
            del B[lb]
            
    return answer
