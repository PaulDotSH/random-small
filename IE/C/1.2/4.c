int search(int x, int A[], int n) {
    for (int i=0; i<n; i++)
        if (A[i]==x)
            return i;
    return -1;
}
