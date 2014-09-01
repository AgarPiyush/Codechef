void mergeSort (int [] A, int p, int s)
{
int q, r;

if (p < s)
{
// Division
q = (s-p)/3;
r = 2*q;

// Conquer
mergeSort(A, p, q);
mergeSort(A, q+1, r);
mergeSort(A, r+1, s);

// Merging
merge(A, p, q, r, s);
}
}

void merge (int [] A, int p, int q, int r, int s)
{
int h,i,j,k; // i sets the first sub-array, j sets the second sub-array, h set the third sub-array, e k sets the present merge-array position

int tamseq1 = q-p+1; // the size of the first sub-array
int tamseq2 = r-q; // the size of the second sub-array
int tamseq3 = s-r; // the size of the third sub-array

int [] seq1 = new int [tamseq1];
for (i = 0; i < seq1.length; ++i)
seq1[i] = A[p+i];

int [] seq2 = new int [tamseq2];
for (j = 0; j < seq2.length; ++j)
seq2[j] = A[q+j+1];

int [] seq3 = new int [tamseq3];
for (h = 0; h < seq3.length; ++h)
seq3[h] = A[r+h+1];

// Merge the three sub-arrays

k = p; i = 0; j = 0; h = 0;

while (i < seq1.length && j < seq2.length && h < seq3.length)
{
// Gets the smallest element of the three sub-arrays

if (seq1[i] <= seq2[j] && seq1[i] <= seq3[h])
{
A[k]= seq1;
i++;
}

else if (seq2[j] <= seq1[i] && seq2[j] <= seq3[h])
{
A[k] = seq2[j];
j++;
}

else if (seq3[h] <= seq1[i] && seq3[h] <= seq2[j])
{
A[k] = seq3[h];
h++;
}

k++;
}

[i] // Completes the merged array with the left over elements

while (i < seq1.length)
{
A[k] = seq1;
k++;
i++;
}

while (j < seq2.length)
{
A[k] = seq2[j];
k++;
j++;
}

while (h < seq3.length)
{
A[k] = seq3[h];
k++;
h++;
}
}
