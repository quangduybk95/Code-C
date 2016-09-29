
//************* COMPARE **************
int compare (elementtype e1, elementtype e2) {
  return (e1.x-e2.x);
}

//************* SWAP **************
void swap (elementtype *a, elementtype *b) {
  elementtype tmp;
  tmp=*a;
  *a=*b;
  *b=tmp;
}

//************* INSERTION SORT *************
void insertion_Sort (elementtype a[], int n) {
  int i,j;
  elementtype key;
  for (j=1;j<=n-1;j++) {
    key=a[j];
    for (i=j-1; i>=0 && compare(a[i],key)>0 ; i--) a[i+1]=a[i];
    a[i+1]=key;
  }
}
//insertion_Sort(a,n);

//************* SELECTION SORT ***************
void selection_Sort (elementtype a[], int n) {
  int i,j,key;
  for (i=0;i<n-1;i++) {
    key=i;
    for (j=i+1;j<=n-1;j++)
      if (compare(a[j],a[key]) < 0)
	key=j;
    swap(&a[i],&a[key]);
  }
}
//selection_Sort(a,n);

//************ BUBBLE SORT ****************
void bubble_Sort (elementtype a[], int n) {
  int i,j;
  for (i=0;i<=n-2;i++)
    for (j=n-1;j>=i+1;j--)
      if (compare(a[j],a[j-1]) < 0)
	swap(&a[j],&a[j-1]);
}
//bubble_Sort(a,n);

//************ MERGE SORT ******************
void MERGE (elementtype a[], int p, int q, int r) {
  int n=r-p+1;
  elementtype *b;
  b=(elementtype*)malloc(n*sizeof(elementtype));
  int i=p,j=q+1,k=0;
  while (i <= q && j <= r) {
    if (compare(a[i],a[j]) < 0) {
      b[k]=a[i]; i++; k++;
    }
    else {
      b[k]=a[j]; j++; k++;
    }
  }
  while (i <= q) {
    b[k]=a[i]; i++; k++;
  }
  while (j <= r) {
    b[k]=a[j]; j++; k++;
  }
  for (i=p,j=0;i<=r,j<n;i++,j++) {
    a[i]=b[j];
  }
  free(b);
}

void merge_Sort (elementtype a[], int p, int r) {
  int q;
  if (p < r) {
    q=(p+r)/2;
    merge_Sort(a,p,q);
    merge_Sort(a,q+1,r);
    MERGE(a,p,q,r);
  }
}
// merge_Sort(a,0,n-1);

//**********************3WAYSORT*************************
void three_way(elementtype a[], int l, int r) {
  if (r <= l) return;
  int i = l-1, j = r;
  int p = l-1, q = r;
  while(1)
    {
      while (compare(a[++i],a[r])<0);
      while (compare(a[r],a[--j])<0) if (j == l) break;
      if (i >= j) break;
      swap(&a[i],&a[j]);
      if (compare(a[i],a[r])==0) swap(&a[++p],&a[i]);
      if (compare(a[j],a[r])==0) swap(&a[--q],&a[j]);
    }
  swap(&a[i],&a[r]);
  j = i - 1;
  i = i + 1;
  int k;
  for (k = l ; k <= p; k++) swap(&a[k],&a[j--]);
  for (k = r-1; k >= q; k--) swap(&a[k],&a[i++]);
  three_way(a, l, j);
  three_way(a, i, r);
}
//3way_sort(a,0,n-1);

//*************** QUICK SORT *************
int partition (elementtype a[], int p, int r) {
  int i,j;
  elementtype pivot;
  pivot=a[r];
  i=p-1;
  for (j=p;j<=r-1;j++) {
    if (compare(a[j],pivot) <= 0) {
      i++;
      swap(&a[i],&a[j]);
    }
  }
  swap(&a[i+1],&a[r]);
  return i+1;
}

void quick_Sort (elementtype a[], int p, int r) {
  int q;
  while (p < r) {
    q=partition(a,p,r);
    quick_Sort(a,p,q-1);
    p=q+1;
  }
}
// quick_Sort(a,0,n-1);

//************** HEAP SORT ************
int parent (int i) {
  return i/2;
}
int left (int i) {
  return 2*i;
}
int right (int i) {
  return 2*i+1;
}

void max_heapify (elementtype a[], int n, int i) {
  int l,r,largest;
  l=left(i);
  r=right(i);
  if (l <= n && compare(a[l],a[i]) > 0)
    largest=l;
  else largest=i;
  if (r <= n && compare(a[r],a[largest]) > 0)
    largest=r;
  if (largest != i) {
    swap(&a[i],&a[largest]);
    max_heapify(a,n,largest);
  }
}

void build_max_heap (elementtype a[], int n) {
  int i;
  for (i=n/2;i>=0;i--) {
    max_heapify(a,n,i);
  }
}

void heap_Sort (elementtype a[], int n) {
  int i;
  build_max_heap(a,n);
  for (i=n-1;i>=1;i--) {
    swap(&a[0],&a[i]);
    max_heapify(a,i-1,0);
  }
}
// heap_Sort(a,n);
//***************************************************
