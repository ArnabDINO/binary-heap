#include<iostream>
using namespace std;

class B_Hip{
	public:
		int* arr;	//this will be used to point to the elements
		int maxize;
		int curSize;	//these are the counter for the maximumsize and current size respectively
		
		//default constructor
		B_Hip(int maxize){
			arr= new int[maxize];
			this-> maxize=maxize;
			curSize = 0;
		}
		
		//the swap function
		void swap (int* a, int* b){
			int temp= *a;
			*a = *b;
			*b = temp;
		}
		
		int parent(int i){
			return (i-1)/2;
		}
		
		int left(int i){
			return (i*2)+1;
		}
		
		int right(int i){
			return (i*2)+2;
		}
		
		int getMin(){
			return arr[0];
		}
		
		//insert function
		void insert(int value){
			if(maxize<=curSize){
				cout<<"maximum capacity reached\n";
				return;
			}
			arr[curSize]=value;
			curSize++;	//the new entry is entered at the end
			
			//now we will take this entry to its designated place
			//check the heap conditions with the parent
			//if false, -> swap
			
			int par_i = curSize-1;
			while(par_i!=0 && arr[parent(par_i)]>arr[par_i]){
				
				swap(&arr[par_i], &arr[parent(par_i)]);
				par_i=parent(par_i);
			}
			cout<<curSize<<endl;
		}
		
		//display funtionalis
		void display(){
			for(int i=0;i<curSize;i++){
				cout<<arr[i]<<",";
			}
			cout<<endl;			
		}
		int xtraktMin(){
			if(curSize<=0){
				return INT_MIN;
			}
			else if(curSize==1){
				curSize--;
				return arr[0];
			}
			
			int root=arr[0];
			arr[0]=arr[curSize-1];
			curSize--;
			minHipify(0);	//minhipify is called in root
			return root;
		}
		
		void decKey(int i, int val){
			arr[i] = val;
			while(i!=0 && arr[parent(i)]>arr[i]){
				swap(&arr[i] ,&arr[parent(i)]);
				i=parent(i);
			}
		}
		
		//delete at palce
		void del_key(int i){
			decKey(i,INT_MIN);
			xtraktMin();
		}
		
		void minHipify(int i){
			int smallest= i; 
        		int l=left(i); 
        		int r=right(i);
        		if(arr[l]<arr[i] && l < curSize){
        			smallest=l;
			}
			if(arr[r] < arr[smallest] && r< curSize){
					smallest=r;
			}
		
        		if(smallest != i){
        			swap( &arr[i], &arr[smallest]);
        			minHipify(smallest);
				}
		}
};

int main(){
	B_Hip bh1(20);
    	for(int i = 10; i >0 ; i--){
        	cout << "Inserting " << i << endl;
        	bh1.insert(i);
       		bh1.display();
    	}
    	bh1.xtraktMin();
    	bh1.display();
   		bh1.del_key(3);
    	bh1.display();
    	cout << endl;
	return 0;
}
