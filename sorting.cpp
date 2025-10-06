#include<iostream>
#include<windows.h>
#include<vector>
using namespace std;
void selectionSort(vector<int>&arr);
void bubbleSort(vector<int>&arr);
void insartionSort(vector<int>&arr);
void mergeSort(vector<int>&arr,int l,int r);
void quickSort(vector<int>&arr,int low,int high);
int main(){
    cout<<endl<<endl;
    cout<<"<------------------- SORTING VISUALIZATION ------------------>"<<endl<<endl;
    cout<<" Click 1 -> selectionSort   "<<endl;
    cout<<" Click 2 -> bubbleSort      "<<endl;
    cout<<" Click 3 -> insertSort      "<<endl;
    cout<<" Click 4 -> mergeSort       "<<endl;
    cout<<" Click 5 -> quickSort       "<<endl;
    cout<<endl<<endl;
    // take array input 
    vector<int>arr;
    for(int i=0;i<10000;i++){
          int p;
          cout<<"Enter number in array (-1 exit) : -> ";
          cin>>p;
          if(p==-1) break;
          arr.push_back(p);
    }
    int n=arr.size();
    cout<<" <--- Your array number is --->"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    
    cout<<endl;

    // take input for select sorting 
      int p;
    do
    {
    cout<<" click 1 to 5 number for select sorting : ";
    cin>>p;
    
    switch (p)
    {
    case 1 : selectionSort(arr); 
        break;
    case 2 : bubbleSort(arr); 
        break;
    case 3 : insartionSort(arr); 
        break;
    case 4 : 
    cout<<"<--- you choose merge sort ---> "<<endl<<endl;
    mergeSort(arr,0,arr.size()-1); 
        break;
    case 5 :
    cout<<"<---- you choose quick sort ----->"<<endl<<endl; 
    quickSort(arr,0,arr.size()-1); 
    cout<<endl;
    cout<<"final array after sorted "<<endl;
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
        break;     
    case -1 : arr.clear();
        break;         
    default:
      cout<<" Please select valid number for sorting "<<endl;
        break;
    }
    } while (p!=-1);
    
}

// selection sort 
void selectionSort(vector<int>&arr){
    cout<<endl<<endl;
    cout<<"you choose selection Sort "<<endl;
    int k=1;
    int n=arr.size();
    for(int i=0;i<n-1;i++){
        int temp=i;
        for(int j=i+1;j<n;j++){
           if(arr[temp]>arr[j]){
            temp=j;
           }
           // print all steps how to any number be change 
           cout<<"step "<<k<<" :-> ";
           for(int l=0;l<n;l++){
            cout<<arr[l]<<" ";
           }
           // i want wait 2 second my program 
           // i want watch how my program exicute 
           Sleep(500);
           // increase steps 
           k++;
           cout<<endl;
        }
        swap(arr[i],arr[temp]);
    }

    cout<<" <--- Your array after sorted  --->"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

 // bubble sort 
void bubbleSort(vector<int>&arr){
    cout<<endl<<endl;
    cout<<"you choose bubbleSort Sort "<<endl;
    int k=1;
    int n=arr.size();
    for(int i=1;i<n;i++){
        for(int j=0;j<n-1;j++){
           if(arr[j]>arr[j+1]){
            swap(arr[j],arr[j+1]);
           }
           // print all steps how to any number be change 
           cout<<"step "<<k<<" :-> ";
           for(int l=0;l<n;l++){
            cout<<arr[l]<<" ";
           }
           // i want wait 2 second my program 
           // i want watch how my program exicute 
           Sleep(500);
           // increase steps 
           k++;
           cout<<endl;
        }
    }

    cout<<" <--- Your array after sorted  --->"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl<<endl;
}

// insertion sort 
void insartionSort(vector<int>&arr){
    cout<<endl<<endl;
    cout<<"you choose insartion Sort "<<endl;
    int k=1;
    int n=arr.size();
    for(int i=1;i<n;i++){
        int temp=arr[i];
        int j=i-1;
        for(;j>=0;j--){
           // print all steps how to any number be change 
           cout<<"step "<<k<<" :-> ";
           for(int l=0;l<n;l++){
            cout<<arr[l]<<" ";
           }
           // i want wait 2 second my program 
           // i want watch how my program exicute 
           Sleep(500);
           // increase steps 
           k++;
           cout<<endl;
            if(arr[j]>temp){
                arr[j+1]=arr[j];
            }else break;
             
        }
        arr[j+1]=temp;
    }

    cout<<" <--- Your array after sorted  --->"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

// merge sort 
void merge(vector<int>& arr, int l, int r){
       int s=l,e=r;
       int mid=s+(e-s)/2;
       
       int len1=mid-s+1;
       int len2=e-mid;
       
       int *first= new int[len1];
       int *second= new int[len2];
       
       int index=s;
       for(int i=0;i<len1;i++){
           first[i]=arr[index++];
       }
       for(int i=0;i<len2;i++){
           second[i]=arr[index++];
       }
       
       index=s;
       int i=0,j=0;
       while(len1>i && len2>j){
           if(first[i]<second[j]){
               arr[index++]=first[i++];
           }else{
               arr[index++]=second[j++];
           }
       }
       while(len1>i){
           arr[index++]=first[i++];
       }
       while(len2>j){
           arr[index++]=second[j++];
       }
       for(int i=l;i<=r;i++){
        cout<<arr[i]<<" ";
       }
       Sleep(500);
       cout<<endl;
       delete []first;
       delete []second;
   }
   
void mergeSort(vector<int>&arr,int l,int r){
    if(l>=r) return;
          int mid=l+(r-l)/2;
          // merge sort left 
         // print half part 
          cout<<"divide in array "<<endl;
          cout<<"left part -> ";
          for(int i=l;i<=mid;i++){
            cout<<arr[i]<<" ";
          }
          cout<<"right part -> ";
          for(int i=mid+1;i<=r;i++){
            cout<<arr[i]<<" ";
          }
          Sleep(500);
          cout<<endl<<endl;
          mergeSort(arr,l,mid);
         
          mergeSort(arr,mid+1,r);
        //   cout<<" how to divide an array "<<endl;
        //   for(int i=l;i<=mid;i++){
        //     cout<<arr[i]<<" ";
        //   }
        //   cout<<"  ";
        //   for(int i=mid+1;i<=r;i++){
        //     cout<<arr[i]<<" ";
        //   }
        //  Sleep(2000);
        //   cout<<endl;
          // mrege two array
          cout<<"merge left and right array "<<endl;
            merge(arr,l,r);
}

// quick sort
 int partition(vector<int>& arr, int low, int high) {
           int pivot=arr[low];
           cout<<"let's take pivot is "<<pivot<<endl;
           int cnt=0;
           for(int i=low+1;i<=high;i++){
               if(arr[i]<=pivot){
                   cnt++;
               }
           }
           int pindex=cnt+low;
           swap(arr[pindex],arr[low]);
           
          int i=low,j=high;
          while(i<pindex && pindex<j){
              while(arr[i]<=pivot){
                  i++;
              }while(arr[j]>pivot){
                  j--;
              }
              if(i<pindex && pindex<j){
                  swap(arr[i++],arr[j--]);
              }
          }
          cout<<"array after pivot element put his best place "<<endl;
          for(int i=low;i<=high;i++){
            cout<<arr[i]<<" ";
          }
          Sleep(500);
          cout<<endl;
        return pindex;
          
    }
 void quickSort(vector<int>& arr, int low, int high) {
        if(low>=high) return ;

        int p=partition(arr,low,high);
        cout<<"partition of the array => "<<endl;
        cout<<"left :-> ";
        for(int i=low;i<=p-1;i++){
            cout<<arr[i]<<" ";
        }
        cout<<"right :-> ";
        for(int i=p+1;i<=high;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        Sleep(500);
        quickSort(arr,low,p-1);
        quickSort(arr,p+1,high);
}
