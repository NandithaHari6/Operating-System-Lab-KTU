#include <stdio.h>  
int main()  
{  
    // P0, P1, P2, P3, P4 are the Process names here  
  
    int n, m, i, j, k;  
    printf("Enter the number of processes");
    scanf("%d",&n);
     printf("Enter the number of resources");
    scanf("%d",&m);
    
    int alloc[n][m];
    printf("Enter the values of allocation matrix ");
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d",&alloc[i][j]);
        }
    }
  
    int max[n][m];
     printf("Enter the values of max matrix ");
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d",&max[i][j]);
        }
    }
    int avail[m];
    printf("Enter the number of available instances of each resource type");
    for(i=0;i<m;i++)
    scanf("%d",&avail[i]);
  
    int f[n], ans[n], ind = 0;  
    for (k = 0; k < n; k++)  
    {  
        f[k] = 0;  
    }  
    int need[n][m];  
    printf("The need matrix is :\n");
    for (i = 0; i < n; i++)  
    {  
        for (j = 0; j < m; j++) { 
            need[i][j] = max[i][j] - alloc[i][j];  
            printf("%d",need[i][j]);}
            printf("\n");
    }  
    int y = 0;  
    for (k = 0; k < 5; k++)  
    {  
        for (i = 0; i < n; i++)  
        {  
            if (f[i] == 0)  
            {  
                int flag = 0;  
                for (j = 0; j < m; j++)  
                {  
                    if (need[i][j] > avail[j])  
                    {  
                        flag = 1;  
                        break;  
                    }  
                }  
                if (flag == 0)  
                {  
                    ans[ind++] = i;  
                    for (y = 0; y < m; y++)  
                        avail[y] += alloc[i][y];  
                    f[i] = 1;  
                }  
            }  
        }  
    }  
    int flag = 1;  
    for (int i = 0; i < n; i++)  
    {  
        if (f[i] == 0)  
        {  
            flag = 0;  
            printf("The following system is not safe");  
            break;  
        }  
    }  
    if (flag == 1)  
    {  
        printf("Following is the SAFE Sequence\n");  
        for (i = 0; i < n - 1; i++)  
            printf(" P%d ->", ans[i]);  
        printf(" P%d", ans[n - 1]);  
    }  
    return (0);  
}  