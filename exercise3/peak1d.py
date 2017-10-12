import math

def peakfind(A, i, j):
    m = int(math.floor((i+j)/2))
    if (A[m-1] <= A[m] and A >= A[m+1]):
        return m
    elif (A[m-1] > A[m]):
        return peakfind(A, i, m-1)
    elif (A[m] < A[m+1]):
        return peakfind(A, m + 1, j)

def main():
    A = [1, 2, 4, 5, 3, 7, 4]
    peak = peakfind(A, 0, 7)
    print(peak)

if __name__=="__main__":
    main()
