#include<stdio.h>
#include<math.h>
//my functions
int find_child(int root);

int child[100][100],child_count=0;
int root,i,j,node,edge,sN,eN,count=0;
int tree[100][100];
int child_semi_final[100],child_final[100];
int edges[100][100];
int temp=0,my_temp=0,my_temp2=0;

int main(){

//open input file
freopen("inp.txt","r",stdin);

//Nodes input;
scanf("%d",&node);
//Edges input
scanf("%d",&edge);

//insert zero in the 2D array
for(i=1;i<=node;i++){
    for(j=1;j<=node;j++){
        tree[i][j]=0;
    }
}

//insert edges
for(i=1;i<=edge;i++){
scanf("%d",&eN);
scanf("%d",&sN);
tree[sN][eN]=eN;

edges[i][1] = sN;
edges[i][2] = eN;
}

//count and find child
for(int node_i=1;node_i<=10;node_i++){
find_child(node_i);
}
//find total child on other side
for(i=2;i<=node;i++){
    for(j=1;j<=node;j++){
             if(child[i][j]!= 0){
             my_temp2 = 1+child_semi_final[child[i][j]];
             temp = temp + my_temp2;
             }
        }
        child_final[i] = child_final[i]+temp;
        temp=0,my_temp=0,my_temp2=0;
}

count=0;
for(i=1;i<=node;i++){
    for(j=2;j<=2;j++){
      temp = child_final[edges[i][j]];
      if(temp != 0){

        if((temp+2)%2!=0){
            count++;
        }
      }
    }
}
printf("%d",count);
return 0;
}


int find_child(int root){
child_count=0;
    for(j=1;j<=node;j++){
            if(tree[root][j]!=0){
                child_count++;
                child[root][child_count]=tree[root][j];
            }
    }
}
