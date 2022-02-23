void findValues(int A[], int n, int vals[]) {
    int min=A[0],max=A[0],s=A[0];
    for (int i=1; i<n; i++)
    {
       if (A[i]>max)
           max=A[i];
       else if (A[i]<min)
           min=A[i];
       s+=A[i];
    }
    vals[0]=min;
    vals[1]=max;
    vals[2]=s;
}