// //Q1 Quick Sort D&Q
// #include <stdio.h>
// void swap(int *a, int *b)
// {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }
//
// int partition(int arr[], int low, int high)
// {
//     int pivot = arr[high];
//     int i = low - 1;
//     for (int j = low; j < high; j++)
//     {
//         if (arr[j] <= pivot)
//         {
//             i++;
//             swap(&arr[i], &arr[j]);
//         }
//     }
//     swap(&arr[i + 1], &arr[high]);
//     return i + 1;
// }

// void quickSort(int arr[], int low, int high)
// {
//     if (low < high)
//     {
//         int pi = partition(arr, low, high);
//         quickSort(arr, low, pi - 1);
//         quickSort(arr, pi + 1, high);
//     }
// }

// int main()
// {
//     int arr[] = {10, 7, 8, 9, 1, 5};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     quickSort(arr, 0, n - 1);
//     printf("Sorted array: ");
//     for (int i = 0; i < n; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     return 0;
// }
//
//---------------------------------------------------------------------------------------------------------
//
//
//
//
//
// Q2 Implementations of Merge Sort using divide and conquer algorithm.
// #include <stdio.h>

// void merge(int arr[], int l, int m, int r)
// {
//     int i, j, k;
//     int n1 = m - l + 1, n2 = r - m;
//     int L[n1], R[n2];

//     for (i = 0; i < n1; i++)
//         L[i] = arr[l + i];
//     for (j = 0; j < n2; j++)
//         R[j] = arr[m + 1 + j];

//     for (i = 0, j = 0, k = l; i < n1 && j < n2; k++)
//     {
//         if (L[i] <= R[j])
//             arr[k] = L[i++];
//         else
//             arr[k] = R[j++];
//     }
//     while (i < n1)
//         arr[k++] = L[i++];
//     while (j < n2)
//         arr[k++] = R[j++];
// }

// void mergeSort(int arr[], int l, int r)
// {
//     if (l < r)
//     {
//         int m = l + (r - l) / 2;
//         mergeSort(arr, l, m);
//         mergeSort(arr, m + 1, r);
//         merge(arr, l, m, r);
//     }
// }

// int main()
// {
//     int arr[] = {10, 7, 8, 9, 1, 5};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     mergeSort(arr, 0, n - 1);
//     printf("Sorted array: ");
//     for (int i = 0; i < n; i++)
//         printf("%d ", arr[i]);
//     return 0;
// }
//---------------------------------------------------------------------------------------------------------
//
//
//
//
//
// Q3 Implementations of Job Sequencing with deadlines using greedy algorithm.
// #include <stdio.h>
// #include <stdlib.h>

// struct Job
// {
//     int id, profit, deadline;
// };

// int compare_jobs(const void *a, const void *b)
// {
//     return ((struct Job *)b)->profit - ((struct Job *)a)->profit;
// }

// void schedule_jobs(struct Job jobs[], int n)
// {
//     qsort(jobs, n, sizeof(struct Job), compare_jobs);
//     int result[n], slots[n], total_profit = 0;
//     for (int i = 0; i < n; i++)
//         slots[i] = 0;
//     for (int i = 0; i < n; i++)
//         for (int j = jobs[i].deadline - 1; j >= 0; j--)
//             if (!slots[j])
//             {
//                 result[j] = i, slots[j] = 1, total_profit += jobs[i].profit;
//                 break;
//             }
//     printf("Scheduled jobs:");
//     for (int i = 0; i < n; i++)
//         if (slots[i])
//             printf(" %d", jobs[result[i]].id);
//     printf("\nTotal profit: %d\n", total_profit);
// }

// int main()
// {
//     struct Job jobs[] = {{1, 200, 5}, {2, 180, 3}, {3, 190, 3}, {4, 300, 2}, {5, 120, 4}, {6, 100, 2}};
//     int n = sizeof(jobs) / sizeof(struct Job);
//     schedule_jobs(jobs, n);
//     return 0;
// }

// int main() {
//     int n;
//     printf("Enter the number of jobs: ");
//     scanf("%d", &n);
//     struct Job jobs[n];
//     for (int i = 0; i < n; i++) {
//         printf("Enter the profit and deadline of job %d: ", i + 1);
//         scanf("%d %d", &jobs[i].profit, &jobs[i].deadline);
//         jobs[i].id = i + 1;
//     }
//     schedule_jobs(jobs, n);
//     return 0;
// }
//---------------------------------------------------------------------------------------------------------
//
//
//
//
// Q4 Implementation of Activity selection problem using greedy algorithm.
//  #include<stdio.h>
//  void swap(int* xp, int* yp)
//  {
//      int temp = *xp;
//      *xp = *yp;
//      *yp = temp;
//  }

// void ActivitySelection(int F[], int S[], int A[], int n)
// {
//     int i, j, k, l;
//     for (i = 0; i < n - 1; i++)
//     {
//         for (j = 0; j < n - i - 1; j++)
//             {
//                 if (F[j] > F[j + 1])
//                 {
//                     swap(&F[j], &F[j + 1]);
//                     swap(&A[j], &A[j + 1]);
//                     swap(&S[j], &S[j + 1]);
//                 }
//             }
//     }
//     printf("Following activities are selected\n");
//     k = 0;
//     printf("%d ", A[k]);
//     for (l = 1; l < n; l++)
//     {
//         if (S[l] >= F[k])
//         {
//             printf("%d ", A[l]);
//             k = l;
//         }
//     }
// }

// int main()
// {
//     int S[100], F[100], A[100], n, i;
//     printf("\nHARSH VIKAS SHETYE_60009210068\n\n");
//     printf("Enter the number of array elements ");
//     scanf("%d",&n);
//     for(i=0;i<n;i++)
//     {
//         A[i]=i+1;
//         printf("Enter the corresponding elements in S and F ");
//         scanf("%d %d", &S[i], &F[i]);
//     }
//     ActivitySelection(F, S, A, n);
//     return 0;
// }

/*
Enter the number of array elements 6
Enter the corresponding elements in S and F 5 9
Enter the corresponding elements in S and F 1 2
Enter the corresponding elements in S and F 3
4
Enter the corresponding elements in S and F 0 6
Enter the corresponding elements in S and F 5 7
Enter the corresponding elements in S and F 8 9
Following activities are selected
2 3 5 6*/
//
//---------------------------------------------------------------------------------------------------------
//
//
//
//
//
// Q5 Implementation of minimum spanning tree using greedy algorithm (Prims’s algorithm).
// #include <stdio.h>
// #include <limits.h>

// #define V 5 // number of vertices in the graph

// int graph[V][V] = {
//     {0, 1, 2, 0, 0},
//     {1, 0, 0, 3, 0},
//     {2, 0, 0, 6, 5},
//     {0, 3, 6, 0, 4},
//     {0, 0, 5, 4, 0}};

// int minKey(int key[], int mstSet[])
// {
//     int min = INT_MAX, min_index;
//     for (int v = 0; v < V; v++)
//         if (mstSet[v] == 0 && key[v] < min)
//             min = key[v], min_index = v;
//     return min_index;
// }

// void printMST(int parent[])
// {
//     int cost = 0;
//     printf("Edge \tWeight\n");
//     for (int i = 1; i < V; i++)
//     {
//         printf("%d - %d \t%d \n", parent[i]+1, i+1, graph[i][parent[i]]);
//         cost += graph[i][parent[i]];
//     }
//     printf("Minimum cost: %d\n", cost);
// }

// void primMST()
// {
//     int parent[V]; // Array to store the constructed MST
//     int key[V];    // Key values used to pick minimum weight edge in cut
//     int mstSet[V]; // To represent set of vertices not yet included in MST
//     for (int i = 0; i < V; i++)
//         key[i] = INT_MAX, mstSet[i] = 0;
//     key[0] = 0;
//     parent[0] = -1;
//     for (int count = 0; count < V - 1; count++)
//     {
//         int u = minKey(key, mstSet);
//         mstSet[u] = 1;
//         for (int v = 0; v < V; v++)
//             if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v])
//                 parent[v] = u, key[v] = graph[u][v];
//     }
//     printMST(parent);
// }

// int main()
// {
//     primMST();
//     return 0;
// }
//---------------------------------------------------------------------------------------------------------
//
//
//
//
//
// Q6Implementation of minimum spanning tree using greedy algorithm (Kruskal’s  algorithm).
// #include <stdio.h>

// int main()
// {
//     int i, j;
//     int min[100];
//     int ignore, sum = 0;
//     int mini, minj;
//     int vali[100];
//     int valj[100];
//     int v;
//     int a[100][100];
//     printf("\nHarsh Shetye_60009210068\nKruskal's Algorithm\n");
//     printf("Enter the number of vertices\n");
//     scanf("%d", &v);
//     for (i = 0; i < v; i++)
//     {
//         for (j = 0; j < v; j++)
//         {
//             printf("Enter value of Ajacency Matrix:\n");
//             scanf("%d", &a[i][j]);
//         }
//     }
//     for (i = 0; i < v; i++)
//     {
//         mini = 0;
//         minj = 0;
//         min[i] = 100;
//         for (j = 0; j < v; j++)
//         {
//             if (a[i][j] <= min[i] && a[i][j] != 0)
//             {
//                 min[i] = a[i][j];
//                 mini = i;
//                 minj = j;
//             }
//         }
//         vali[i] = mini;
//         valj[i] = minj;
//     }
//     for (i = 0; i < v - 1; i++)
//     {
//         if (vali[i] == valj[i + 1] && vali[i + 1] == valj[i])
//         {
//             ignore = i;
//         }
//     }
//     printf("\nFollowing are the minimum edge weights:\n");
//     for (i = 0; i < v; i++)
//     {
//         if (i != ignore)
//         {
//             printf("{%d , %d} = %d\n", vali[i] + 1, valj[i] + 1, min[i]);
//             sum += min[i];
//         }
//     }
//     printf("\nThe cost of MST is:%d\n", sum);
//     return 0;
// }
//---------------------------------------------------------------------------------------------------------
//
//
//
//
//
//
// Q7 Implementation of Shortest paths using greedy algorithm.

// #include <stdio.h>
// #include <stdlib.h>
// #include <limits.h>

// #define V 4 // number of vertices in the graph

// // function to find the vertex with the minimum distance value
// int minDistance(int dist[], int visited[])
// {
//     int min = INT_MAX, min_index;
//     for (int v = 0; v < V; v++)
//         if (visited[v] == 0 && dist[v] <= min)
//             min = dist[v], min_index = v;
//     return min_index;
// }

// // function to print the shortest path from source to destination vertex
// void printPath(int parent[], int j)
// {
//     if (parent[j] == -1)
//         return;
//     printPath(parent, parent[j]);
//     printf("%d ", j);
// }

// // function to print the shortest distance between the source and all other vertices
// void printSolution(int dist[], int parent[], int src)
// {
//     printf("Vertex\t\t Distance\tPath");
//     for (int i = 0; i < V; i++)
//     {
//         if (i != src)
//         {
//             printf("\n%d -> %d \t\t %d\t\t%d ", src, i, dist[i], src);
//             printPath(parent, i);
//         }
//     }
// }

// // function to implement Dijkstra's algorithm
// void dijkstra(int graph[V][V], int src)
// {
//     int dist[V];
//     int visited[V];
//     int parent[V];

//     // initialization
//     for (int i = 0; i < V; i++)
//     {
//         parent[src] = -1;
//         dist[i] = INT_MAX;
//         visited[i] = 0;
//     }
//     dist[src] = 0;

//     // find shortest path for all vertices
//     for (int count = 0; count < V - 1; count++)
//     {
//         int u = minDistance(dist, visited);
//         visited[u] = 1;

//         for (int v = 0; v < V; v++)
//         {
//             if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
//             {
//                 parent[v] = u;
//                 dist[v] = dist[u] + graph[u][v];
//             }
//         }
//     }

//     // print the solution
//     printSolution(dist, parent, src);
// }

// int main()
// {
//     int graph[V][V] = {{0, 1, 3, 0},
//                        {0, 0, 1, 10},
//                        {0, 0, 0, 4},
//                        {0, 0, 0, 0}};

//     dijkstra(graph, 0);

//     return 0;
// }
//---------------------------------------------------------------------------------------------------------
//
//
//
//
//
//
// Q8 Implementation of Knapsack problem using greedy algorithm.

// #include <stdio.h>
// #include <stdlib.h>
// #define MAX_N 100

// struct item {
//     int id;
//     int profit;
//     int weight;
//     float ratio;
// };

// int compare(const void* a, const void* b) {
//     struct item* item1 = (struct item*) a;
//     struct item* item2 = (struct item*) b;
//     float ratio1 = item1->ratio;
//     float ratio2 = item2->ratio;
//     if (ratio1 < ratio2) {
//         return 1;
//     } else if (ratio1 > ratio2) {
//         return -1;
//     } else {
//         return 0;
//     }
// }

// void fractionalKnapsack(int n, int capacity, struct item items[]) {
//     int i;
//     float total_profit = 0.0;
//     float fraction[MAX_N] = {0.0};

//     for (i = 0; i < n; i++) {
//         items[i].ratio = (float) items[i].profit / (float) items[i].weight;
//     }

//     qsort(items, n, sizeof(struct item), compare);

//     for (i = 0; i < n; i++) {
//         if (capacity == 0) {
//             break;
//         } else if (items[i].weight <= capacity) {
//             fraction[items[i].id] = 1.0;
//             total_profit += items[i].profit;
//             capacity -= items[i].weight;
//         } else {
//             fraction[items[i].id] = (float) capacity / (float) items[i].weight;
//             total_profit += fraction[items[i].id] * items[i].profit;
//             capacity = 0;
//         }
//     }

//     printf("Selected items and their fractions:\n");
//     for (i = 0; i < n; i++) {
//         if (fraction[i] > 0.0) {
//             printf("Item %d: %.2f\n", i+1, fraction[i]);
//         }
//     }
//     printf("Maximum profit: %.2f\n", total_profit);
// }

// int main() {
//     int n, capacity, i;
//     struct item items[MAX_N];
//     printf("\nHarsh Shetye_60009210068_Knapsack\n");

//     printf("Enter the capacity of the knapsack: ");
//     scanf("%d", &capacity);
//     printf("Enter the number of items: ");
//     scanf("%d", &n);
//     for (i = 0; i < n; i++) {
//         printf("Enter the weight and profit of each item:\n");
//         scanf("%d %d", &items[i].weight, &items[i].profit);
//         items[i].id = i;
//     }

//     fractionalKnapsack(n, capacity, items);
//     return 0;
// }
//
//---------------------------------------------------------------------------------------------------------
//
//
//
//
//
// Q Selection Sort
// #include <stdio.h>

// void selectionSort(int arr[], int n)
// {
//     int i, j, minIndex, temp;

//     for (i = 0; i < n - 1; i++)
//     {
//         minIndex = i;
//         for (j = i + 1; j < n; j++)
//         {
//             if (arr[j] < arr[minIndex])
//             {
//                 minIndex = j;
//             }
//         }
//         // Swap the found minimum element with the first element
//         temp = arr[minIndex];
//         arr[minIndex] = arr[i];
//         arr[i] = temp;
//     }
// }

// void printArray(int arr[], int n)
// {
//     int i;
//     for (i = 0; i < n; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");
// }

// int main()
// {
//     int arr[] = {64, 25, 12, 22, 11};
//     int n = sizeof(arr) / sizeof(arr[0]);

//     printf("Original array: ");
//     printArray(arr, n);

//     selectionSort(arr, n);

//     printf("Sorted array: ");
//     printArray(arr, n);

//     return 0;
// }

//---------------------------------------------------------------------------------------------------------
//
//
//
//
//
// Q9  Implementation of Job Scheduling Problem using greedy algorithm.
//  repeated
//---------------------------------------------------------------------------------------------------------
//
//
//
//
//
//
// Q10 Implementation of Huffman code using greedy algorithm.

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <stdbool.h>

// #define MAX_TREE_HT 100

// struct node
// {
//     char data;
//     unsigned frequency;
//     struct node *left, *right;
// };

// struct min_heap
// {
//     unsigned size;
//     unsigned capacity;
//     struct node **array;
// };

// struct node *new_node(char data, unsigned frequency)
// {
//     struct node *node = (struct node *)malloc(sizeof(struct node));
//     node->data = data;
//     node->frequency = frequency;
//     node->left = node->right = NULL;
//     return node;
// }

// struct min_heap *create_min_heap(unsigned capacity)
// {
//     struct min_heap *min_heap = (struct min_heap *)malloc(sizeof(struct min_heap));
//     min_heap->size = 0;
//     min_heap->capacity = capacity;
//     min_heap->array = (struct node **)malloc(min_heap->capacity * sizeof(struct node *));
//     return min_heap;
// }

// void swap_node(struct node **a, struct node **b)
// {
//     struct node *temp = *a;
//     *a = *b;
//     *b = temp;
// }

// void min_heapify(struct min_heap *min_heap, int idx)
// {
//     int smallest = idx;
//     int left = 2 * idx + 1;
//     int right = 2 * idx + 2;
//     if (left < min_heap->size && min_heap->array[left]->frequency < min_heap->array[smallest]->frequency)
//         smallest = left;
//     if (right < min_heap->size && min_heap->array[right]->frequency < min_heap->array[smallest]->frequency)
//         smallest = right;
//     if (smallest != idx)
//     {
//         swap_node(&min_heap->array[smallest], &min_heap->array[idx]);
//         min_heapify(min_heap, smallest);
//     }
// }

// bool is_size_one(struct min_heap *min_heap)
// {
//     return (min_heap->size == 1);
// }

// struct node *extract_min(struct min_heap *min_heap)
// {
//     struct node *temp = min_heap->array[0];
//     min_heap->array[0] = min_heap->array[min_heap->size - 1];
//     --min_heap->size;
//     min_heapify(min_heap, 0);
//     return temp;
// }

// void insert_min_heap(struct min_heap *min_heap, struct node *node)
// {
//     ++min_heap->size;
//     int i = min_heap->size - 1;
//     while (i && node->frequency < min_heap->array[(i - 1) / 2]->frequency)
//     {
//         min_heap->array[i] = min_heap->array[(i - 1) / 2];
//         i = (i - 1) / 2;
//     }
//     min_heap->array[i] = node;
// }

// bool is_leaf(struct node *node)
// {
//     return !(node->left) && !(node->right);
// }

// struct min_heap *create_and_build_min_heap(char data[], int frequency[], int size)
// {
//     struct min_heap *min_heap = create_min_heap(size);
//     for (int i = 0; i < size; ++i)
//         min_heap->array[i] = new_node(data[i], frequency[i]);
//     min_heap->size = size;
//     for (int i = size / 2 - 1; i >= 0; --i)
//         min_heapify(min_heap, i);
//     return min_heap;
// }

// struct node *build_huffman_tree(char data[], int frequency[], int size)
// {
//     struct node *left, *right, *top;
//     struct min_heap *min_heap = create_and_build_min_heap(data, frequency, size);
//     while (!is_size_one(min_heap))
//     {
//         left = extract_min(min_heap);
//         right = extract_min(min_heap);
//         top = new_node('$', left->frequency + right->frequency);
//         top->left = left;
//         top->right = right;
//         insert_min_heap(min_heap, top);
//     }
//     return extract_min(min_heap);
// }

// void print_codes(struct node *root, int arr[], int top)
// {
//     if (root->left)
//     {
//         arr[top] = 0;
//         print_codes(root->left, arr, top + 1);
//     }
//     if (root->right)
//     {
//         arr[top] = 1;
//         print_codes(root->right, arr, top + 1);
//     }
//     if (is_leaf(root))
//     {
//         printf("%c: ", root->data);
//         for (int i = 0; i < top; ++i)
//             printf("%d", arr[i]);
//         printf("\n");
//     }
// }

// void huffman_code(char data[], int frequency[], int size)
// {
//     struct node *root = build_huffman_tree(data, frequency, size);
//     int arr[MAX_TREE_HT], top = 0;
//     print_codes(root, arr, top);
// }

// int main()
// {
//     char data[] = {'a', 'b', 'c', 'd', 'e'};
//     int frequency[] = {35, 12, 8, 25, 20};
//     int size = sizeof(data) / sizeof(data[0]);
//     huffman_code(data, frequency, size);
//     return 0;
// }

//---------------------------------------------------------------------------------------------------------
//
//
//
//
//
// Q11 Implementation of fractional Knapsack using greedy algorithm.
//  repeated
//---------------------------------------------------------------------------------------------------------
//
//
//
//
//
//
// Q 12 Implementation of Coin Change Problem using dynamic programming.

// #include <stdio.h>

// int min(int a, int b)
// {
//     if (a < b)
//         return a;
//     else
//         return b;
// }

// int main()
// {
//     int deno[100];
//     printf("Harsh Shetye_60009210068_Dynamic Programming_Coin Change Problem\n\n");
//     printf("Enter the number of Denominations : ");
//     int n = 0;
//     scanf("%d", &n);
//     int i = 1;
//     while (i < n + 1)
//     {
//         printf("enter the value of %dth denomination : ", i);
//         scanf("%d", &deno[i]);
//         i++;
//     }
//     int target = 0;
//     printf("Enter the target sum : ");
//     scanf("%d", &target);
//     int dp[100][100] = {0};
//     for (int j = 1; j < target + 1; j++)
//     {
//         for (i = 1; i < n + 1; i++)
//         {
//             if ((i == 1 && i == j) || (i == 1))
//             {
//                 dp[i][j] = 1 + dp[1][j - deno[i]];
//             }
//             else if (j < deno[i])
//             {
//                 dp[i][j] = dp[i - 1][j];
//             }
//             else
//             {
//                 dp[i][j] = min(dp[i - 1][j], (1 + dp[i][j - deno[i]]));
//             }
//         }
//     }
//     printf("\nThe least number of coins required is : %d \n\n", dp[n][target]);
//     int solution[100] = {0};
//     i = n;
//     int k = 0;
//     int j = target;
//     while (j > 0)
//     {
//         if (dp[i][j] == dp[i - 1][j])
//         {
//             i--;
//             continue;
//         }
//         else
//         {
//             target = target - deno[i];
//             solution[k] = deno[i];
//             k++;
//             j = target;
//             continue;
//         }
//     }
//     i = 0;
//     while (i < k)
//     {
//         printf("The %dth coin in the solution set is : %d \n", i + 1, solution[i]);
//         i++;
//     }
//     return 0;
// }
//---------------------------------------------------------------------------------------------------------
//
//
//
//
//
//
// Q13 Implementation of Knapsack problem using dynamic programming.
// #include<stdio.h>
// #include<string.h>
// #define MAX 100
// #define max(a,b) ((a>b)?a:b)

// int dp[MAX][MAX];

// int knapsack(int W, int wt[], int val[], int n) {
//     int i, w, selected_items[n];
//     memset(selected_items,0,sizeof(selected_items));
//     for (i = 0; i <= n; i++) {
//         for (w = 0; w <= W; w++) {
//             if (i == 0 || w == 0)
//                 dp[i][w] = 0;
//             else if (wt[i-1] > w)
//                 dp[i][w] = dp[i - 1][w];
//             else
//                 dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
//         }
//     }
//         // print maximum value that can be put in a knapsack of capacity W
//     printf("Maximum value: %d\n", dp[n][W]);

//     // find items included in the knapsack
//     i = n;
//     w = W;
//     int j = 0;
//     while (i > 0 && w > 0) {
//         if (dp[i][w] != dp[i - 1][w]) {
//             selected_items[j] = 1;
//             w = w - wt[i - 1];
//             i--;
//             j++;
//         } else {
//             i--;
//             j++;
//         }
//     }

//     // print selected items
//     printf("Selected items: ");
//     for (i = n - 1; i >= 0; i--) {
//         printf("%d ", selected_items[i]);
//     }
// }

// int main() {
//     int n, W, i;
//     int wt[MAX], val[MAX];
//     printf("Enter the number of items: ");
//     scanf("%d", &n);
//     printf("Enter the weight and value of each item:\n");
//     for (i = 0; i < n; i++)
//         scanf("%d%d", &wt[i], &val[i]);
//     printf("Enter the capacity of the knapsack: ");
//     scanf("%d", &W);
//     knapsack(W, wt, val, n);

//     return 0;
// }
//---------------------------------------------------------------------------------------------------------
//
//
//
//
//
//
// Q14 Implementation of Matrix chain multiplication using dynamic programming.
// #include <stdio.h>
// int p[100];
// int karr[100][100];
// int MandM(int n, int i, int j)
// {
//     int k;
//     int min = 10000000;
//     int mink;
//     int count;
//     if (i == j)
//     {
//         mink = 0;
//         return 0;
//     }
//     for (k = i; k < j; k++)
//     {
//         count = MandM(n, i, k) + MandM(n, k + 1, j) + p[i - 1] * p[k] * p[j];
//         if (count < min)
//         {
//             min = count;
//             mink = k;
//         }
//     }
//     karr[i][j] = mink;
//     return min;
// }
// void print_parenthesis(int i, int j)
// {
//     if (i == j)
//     {
//         printf("A%d", i);
//     }
//     else
//     {
//         printf("(");
//         print_parenthesis(i, karr[i][j]);
//         print_parenthesis(karr[i][j] + 1, j);
//         printf(")");
//     }
// }

// int main()
// {
//     int i, j, m, n, q[100][100], k[100];
//     printf("\nHarsh Shetye_60009210068_Matrix Chain Multiplication_DP\n");
//     printf("Enter the number of sequences\n");
//     scanf("%d", &n);
//     printf("Enter the sequence one by one\n");
//     for (i = 0; i < n; i++)
//         scanf("%d", &p[i]);
//     for (i = 0; i < n; i++)
//     {
//         for (j = i; j < n; j++)
//         {
//             q[i][j] = MandM(n, i, j);
//         }
//     }
//     printf("\nCost/Comparison\n\n");
//     for (i = 1; i < n; i++)
//     {
//         for (m = 0; m < i; m++)
//         {
//             printf(" ");
//         }
//         for (j = i; j < n; j++)
//         {
//             printf("%d ", q[i][j]);
//         }
//         printf("\n");
//     }
//     printf("\nValue of k\n\n");
//     for (i = 1; i < n; i++)
//     {
//         for (m = 0; m < i; m++)
//         {
//             printf("  ");
//         }
//         for (j = i; j < n; j++)
//         {
//             printf("%d ", karr[i][j]);
//         }
//         printf("\n");
//     }
//     printf("Optimal Parenthesis: ");
//     print_parenthesis(1, n - 1);
//     printf("\n");
// }
//
//---------------------------------------------------------------------------------------------------------
//
//
//
//
//
//
//
// Q15 Implementation of Longest Common Subsequence (LCS) using dynamic programming.
// #include <stdio.h>
// #include <string.h>

// int i, j, m, n, c[50][50];
// char x[50], y[50], b[50][50];

// void print_lcs(int i, int j)
// {
//     if (i == 0 || j == 0)
//         return;
//     if (b[i][j] == 'c')
//     {
//         print_lcs(i - 1, j - 1);
//         printf("%c", x[i - 1]);
//     }
//     else if (b[i][j] == 'u')
//         print_lcs(i - 1, j);
//     else
//         print_lcs(i, j - 1);
// }

// void lcs()
// {
//     m = strlen(x);
//     n = strlen(y);
//     for (i = 0; i <= m; i++)
//         c[i][0] = 0;
//     for (i = 0; i <= n; i++)
//         c[0][i] = 0;

//     for (i = 1; i <= m; i++)
//         for (j = 1; j <= n; j++)
//         {
//             if (x[i - 1] == y[j - 1])
//             {
//                 c[i][j] = c[i - 1][j - 1] + 1;
//                 b[i][j] = 'c';
//             }
//             else if (c[i - 1][j] >= c[i][j - 1])
//             {
//                 c[i][j] = c[i - 1][j];
//                 b[i][j] = 'u';
//             }
//             else
//             {
//                 c[i][j] = c[i][j - 1];
//                 b[i][j] = 'l';
//             }
//         }
// }

// int main()
// {
//     printf("\nHarsh Shetye_60009210068_LCS_DAOA\n");
//     printf("\nEnter 1st sequence : ");
//     scanf("%s", x);
//     printf("Enter 2nd sequence : ");
//     scanf("%s", y);
//     printf("\nThe Longest Common Subsequence is ");
//     lcs();
//     print_lcs(m, n);
//     return 0;
// }
//---------------------------------------------------------------------------------------------------------
//
//
//
//
//
//
//
// Q16 Implementation of Travelling Salesman Problem using dynamic programming.
// #include <stdio.h>
// int a[10][10], visited[10], n, cost = 0;

// int least(int c)
// {
//     int i, nc = 999;
//     int min = 999, kmin;
//     for (i = 0; i < n; i++)
//     {
//         if ((a[c][i] != 0) && (visited[i] == 0))
//             if (a[c][i] < min)
//             {
//                 min = a[i][0] + a[c][i];
//                 kmin = a[c][i];
//                 nc = i;
//             }
//     }
//     if (min != 999)
//         cost += kmin;
//     return nc;
// }
// void get()
// {
//     int i, j;
//     printf("Enter No. of Cities: ");
//     scanf("%d", &n);
//     printf("\nEnter Cost Matrix\n");
//     for (i = 0; i < n; i++)
//     {
//         printf("\nEnter Elements of Row # : %d\n", i + 1);
//         for (j = 0; j < n; j++)
//             scanf("%d", &a[i][j]);
//         visited[i] = 0;
//     }
//     printf("\n\nThe cost list is:\n\n");
//     for (i = 0; i < n; i++)
//     {
//         printf("\n\n");
//         for (j = 0; j < n; j++)
//             printf("\t%d", a[i][j]);
//     }
// }
// void mincost(int city)
// {
//     int i, ncity;
//     visited[city] = 1;
//     printf("%d -->", city + 1);
//     ncity = least(city);
//     if (ncity == 999)
//     {
//         ncity = 0;
//         printf("%d", ncity + 1);
//         cost += a[city][ncity];
//         return;
//     }
//     mincost(ncity);
// }
// void put()
// {
//     printf("\n\nMinimum cost:");
//     printf("%d", cost);
// }
// int main()
// {
//     get();
//     printf("\n\nThe Path is:\n\n");
//     mincost(0);
//     put();
//     return 0;
// }

//---------------------------------------------------------------------------------------------------------
//
//
//
//
//
//
// Q17 N Queen Problem

// #include <stdio.h>
// #include <math.h>

// int a[30], count = 0;

// int place(int pos)
// {
//     for (int i = 1; i < pos; i++)
//         if (a[i] == a[pos] || abs(a[i] - a[pos]) == abs(i - pos))
//             return 0;
//     return 1;
// }

// void print_sol(int n)
// {
//     count++;
//     printf("\n\nSolution #%d:\n", count);
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= n; j++)
//             printf("%s\t", a[i] == j ? "Q" : "*");
//         printf("\n");
//     }
// }

// void queen(int n, int k)
// {
//     if (k > n)
//         return print_sol(n);
//     for (a[k] = 1; a[k] <= n; a[k]++)
//         if (place(k))
//             queen(n, k + 1);
// }

// int main()
// {
//     int n;
//     printf("N_Queen\n\n");
//     printf("Enter the number of Queens: ");
//     scanf("%d", &n);
//     queen(n, 1);
//     printf("\nTotal Solutions=%d", count);
//     return 0;
// }
//---------------------------------------------------------------------------------------------------------
//
//
//
//
//
// Q18 Implementation of Sum of subsets using backtracking.
// #include <stdio.h>

// void findSubsets(int set[], int n, int sum, int subset[], int count, int start)
// {
//     if (sum == 0)
//     {
//         printf("{ ");
//         for (int i = 0; i < count; i++)
//         {
//             printf("%d ", subset[i]);
//         }
//         printf("}\n");
//         return;
//     }
//     for (int i = start; i < n; i++)
//     {
//         if (set[i] <= sum)
//         {
//             subset[count] = set[i];
//             findSubsets(set, n, sum - set[i], subset, count + 1, i + 1);
//         }
//     }
// }
// int main()
// {
//     int n, sum;
//     printf("\nHarsh Shetye_60009210068_Sum of Subsets\n");
//     printf("Enter the size of the array: ");
//     scanf("%d", &n);
//     int set[n];
//     printf("Enter the elements of the array: ");
//     for (int i = 0; i < n; i++)
//     {
//         scanf("%d", &set[i]);
//     }
//     printf("Enter the target sum: ");
//     scanf("%d", &sum);
//     int subset[n];
//     findSubsets(set, n, sum, subset, 0, 0);
//     return 0;
// }
//---------------------------------------------------------------------------------------------------------
//
//
//
//
//
//
// Q19 Implementation of Fifteen Puzzle problem using branch and bound
// #include <stdio.h>
// #include <conio.h>

// int m = 0, n = 4;

// int cal(int temp[10][10], int t[10][10])
// {
//     int i, j, m = 0;
//     for (i = 0; i < n; i++)
//         for (j = 0; j < n; j++)
//             if (temp[i][j] != t[i][j])
//                 m++;
//     return m;
// }

// int check(int a[10][10], int t[10][10])
// {
//     int i, j, f = 1;
//     for (i = 0; i < n; i++)
//         for (j = 0; j < n; j++)
//             if (a[i][j] != t[i][j])
//                 f = 0;
//     return f;
// }

// int main()
// {
//     int p, i, j, n = 4, a[10][10], t[10][10], temp[10][10], r[10][10];
//     int m = 0, x = 0, y = 0, d = 1000, dmin = 0, l = 0;
//     printf("\nEnter the matrix to be solved,space with zero :\n");
//     for (i = 0; i < n; i++)
//         for (j = 0; j < n; j++)
//             scanf("%d", &a[i][j]);

//     printf("\nEnter the target matrix,space with zero :\n");
//     for (i = 0; i < n; i++)
//         for (j = 0; j < n; j++)
//             scanf("%d", &t[i][j]);

//     printf("\nEntered Matrix is :\n");
//     for (i = 0; i < n; i++)
//     {
//         for (j = 0; j < n; j++)
//             printf("%d\t", a[i][j]);
//         printf("\n");
//     }

//     printf("\nTarget Matrix is :\n");
//     for (i = 0; i < n; i++)
//     {
//         for (j = 0; j < n; j++)
//             printf("%d\t", t[i][j]);
//         printf("\n");
//     }

//     while (!(check(a, t)))
//     {
//         l++;
//         d = 1000;
//         for (i = 0; i < n; i++)
//             for (j = 0; j < n; j++)
//             {
//                 if (a[i][j] == 0)
//                 {
//                     x = i;
//                     y = j;
//                 }
//             }

//         // To move upwards
//         for (i = 0; i < n; i++)
//             for (j = 0; j < n; j++)
//                 temp[i][j] = a[i][j];

//         if (x != 0)
//         {
//             p = temp[x][y];
//             temp[x][y] = temp[x - 1][y];
//             temp[x - 1][y] = p;
//         }
//         m = cal(temp, t);
//         dmin = l + m;
//         if (dmin < d)
//         {
//             d = dmin;
//             for (i = 0; i < n; i++)
//                 for (j = 0; j < n; j++)
//                     r[i][j] = temp[i][j];
//         }

//         // To move downwards
//         for (i = 0; i < n; i++)
//             for (j = 0; j < n; j++)
//                 temp[i][j] = a[i][j];
//         if (x != n - 1)
//         {
//             p = temp[x][y];
//             temp[x][y] = temp[x + 1][y];
//             temp[x + 1][y] = p;
//         }
//         m = cal(temp, t);
//         dmin = l + m;
//         if (dmin < d)
//         {
//             d = dmin;
//             for (i = 0; i < n; i++)
//                 for (j = 0; j < n; j++)
//                     r[i][j] = temp[i][j];
//         }

//         // To move right side
//         for (i = 0; i < n; i++)
//             for (j = 0; j < n; j++)
//                 temp[i][j] = a[i][j];
//         if (y != n - 1)
//         {
//             p = temp[x][y];
//             temp[x][y] = temp[x][y + 1];
//             temp[x][y + 1] = p;
//         }
//         m = cal(temp, t);
//         dmin = l + m;
//         if (dmin < d)
//         {
//             d = dmin;
//             for (i = 0; i < n; i++)
//                 for (j = 0; j < n; j++)
//                     r[i][j] = temp[i][j];
//         }

//         // To move left
//         for (i = 0; i < n; i++)
//             for (j = 0; j < n; j++)
//                 temp[i][j] = a[i][j];
//         if (y != 0)
//         {
//             p = temp[x][y];
//             temp[x][y] = temp[x][y - 1];
//             temp[x][y - 1] = p;
//         }
//         m = cal(temp, t);
//         dmin = l + m;
//         if (dmin < d)
//         {
//             d = dmin;
//             for (i = 0; i < n; i++)
//                 for (j = 0; j < n; j++)
//                     r[i][j] = temp[i][j];
//         }

//         printf("\nCalculated Intermediate Matrix Value :\n");
//         for (i = 0; i < n; i++)
//         {
//             for (j = 0; j < n; j++)
//             {
//                 printf("%d\t", r[i][j]);
//                 a[i][j] = r[i][j];
//                 temp[i][j] = 0;
//             }
//             printf("\n");
//         }
//     }
//     return 0;
// }

//---------------------------------------------------------------------------------------------------------
//
//
//
//
//
//
//
// Q 20 Implementation of Rabin-Karp string matching algorithm
// #include <stdio.h>
// #include <string.h>

// #define d 256 // Number of characters in the input alphabet
// #define q 101 // A prime number used for hashing

// void search(char *pat, char *txt)
// {
//     int M = strlen(pat);
//     int N = strlen(txt);
//     int i, j;
//     int p = 0; // Hash value for pattern
//     int t = 0; // Hash value for text
//     int h = 1;

//     // The value of h would be "pow(d, M-1)%q"
//     for (i = 0; i < M - 1; i++)
//         h = (h * d) % q;

//     // Calculate the hash value of pattern and first window of text
//     for (i = 0; i < M; i++)
//     {
//         p = (d * p + pat[i]) % q;
//         t = (d * t + txt[i]) % q;
//     }

//     // Slide the pattern over text one by one
//     for (i = 0; i <= N - M; i++)
//     {
//         // Check the hash values of current window of text and pattern
//         if (p == t)
//         {
//             // Check for characters one by one
//             for (j = 0; j < M; j++)
//             {
//                 if (txt[i + j] != pat[j])
//                     break;
//             }

//             // If pattern is present at current position, print it
//             if (j == M)
//                 printf("Pattern found at index %d \n", i);
//         }

//         // Calculate hash value for next window of text
//         if (i < N - M)
//         {
//             t = (d * (t - txt[i] * h) + txt[i + M]) % q;

//             // We might get negative value of t, converting it to positive
//             if (t < 0)
//                 t = (t + q);
//         }
//     }
// }

// int main()
// {
//     char txt[100];
//     char pat[100];

//     printf("Enter the text string: ");
//     scanf("%s", txt);

//     printf("Enter the pattern string: ");
//     scanf("%s", pat);

//     search(pat, txt);
//     return 0;
// }
//---------------------------------------------------------------------------------------------------------
//
//
//
//
//
// Q21 Implementation of Knuth-Morris-Pratt string matching algorithm
// #include <stdio.h>
// #include <string.h>

// void computeLPSArray(char *pat, int M, int *lps)
// {
//     int len = 0;
//     lps[0] = 0;
//     int i = 1;

//     while (i < M)
//     {
//         if (pat[i] == pat[len])
//         {
//             len++;
//             lps[i] = len;
//             i++;
//         }
//         else
//         {
//             if (len != 0)
//                 len = lps[len - 1];
//             else
//             {
//                 lps[i] = 0;
//                 i++;
//             }
//         }
//     }
// }

// void KMPSearch(char *pat, char *txt)
// {
//     int M = strlen(pat);
//     int N = strlen(txt);
//     int lps[M];
//     int j = 0;

//     computeLPSArray(pat, M, lps);

//     int i = 0;
//     while (i < N)
//     {
//         if (pat[j] == txt[i])
//         {
//             j++;
//             i++;
//         }

//         if (j == M)
//         {
//             printf("Pattern found at index %d \n", i - j);
//             j = lps[j - 1];
//         }
//         else if (i < N && pat[j] != txt[i])
//         {
//             if (j != 0)
//                 j = lps[j - 1];
//             else
//                 i++;
//         }
//     }
// }

// int main()
// {
//     char txt[100];
//     char pat[100];

//     printf("Enter the text string: ");
//     scanf("%s", txt);

//     printf("Enter the pattern string: ");
//     scanf("%s", pat);

//     KMPSearch(pat, txt);

//     return 0;
// }
