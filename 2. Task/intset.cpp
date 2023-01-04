#include "intset.h"



void IntSet::Push(int element) {
	for(int i = 0; i < right - left + 1; i++){
		
	} 

}

IntSet::IntSet(IntSet& s);{
	
 
}
 
int IntSet::Max(){
	max = right;
	for(int i = 0; i < power + 1; i++){
		if( set[i] <= max){
			max = max;
		}else{
			max = set[i];
		}
	}
	return max;
}


int IntSet::Min() {
	min = left;
	for(int i = 0; i < power + 1; i++){
		if(set[i] >= min){
			min = min;
		}else{
			min = set[i];
		}
	}
	return min;
}


bool IntSet::IsEmpty() {
	if(power == 0 && set[0] != right){
		return true;
	}else{
		return false;
	}
}


