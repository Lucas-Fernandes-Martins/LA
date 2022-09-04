#include<iostream>
#include<vector>


using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::stod;

class matrix{
	
	private:
	
	double** m;

	int dim_x;
	int dim_y;
	
	public:

	matrix(string *input){
		
		if((*input)[0] != '{'){
			cout << "Invalid input! " << endl;
			exit(1);
		}
		
		dim_x = 1;

		string buffer;

		vector<double> clean_input;
			
		bool count_x = true;
		
		for(int i = 0; i < input->size() -1; i++){
			if((*input)[i] == ' ') continue;

			if((*input)[i] == ',' && count_x) dim_x++;	

			if((*input)[i] == '}'){
				dim_y++;
				count_x = false;
			}

			if((*input)[i] == ','){
				clean_input.push_back(stod(buffer));
				buffer.clear();
			}else if((*input)[i] != '{'){
				buffer.push_back((*input)[i]);
			}
			

		}

		clean_input.push_back(stod(buffer));
		
		m = (double**) malloc(sizeof(double*)*dim_y);
				
		for(int i = 0; i < clean_input.size(); i++){
			cout << clean_input.at(i) << " , ";
		}

		cout << endl;

		int count = 0;
		for(int i = 0; i < dim_y; i++){
			m[i] = (double*) malloc(sizeof(double)*dim_x);
			for(int j = 0; j < dim_x; j++){
				m[i][j] = clean_input.at(count);
				count++;
			}
		}

	}

	void print_matrix(){
		cout << "--------------------------------" << endl;
		for(int i = 0; i < dim_y; i++){
			for(int j = 0; j < dim_x; j++){
				cout << " " << m[i][j];
			}

			cout << endl;
		}

		cout << "-------------------------------" << endl;
	}

	const matrix& operator + (const matrix& a){
		if(a.dim_x != this->dim_x || a.dim_y != this->dim_y){
			cout << "Different dimensions! Impossible operation" << endl;
			exit(1);
		}

		for(int i = 0; i < dim_y; i++){
			for(int j = 0; j < dim_x; j++){
				(this->m)[i][j] = (this->m)[i][j] + (a.m)[i][j];
			}
		}

		return *this;	
	}

	/*
	const matrix& lu(){
		
	}
	*/
};


void eigenvalues(int** m){
	return;
}


int main(){
		
	std::string input = "{{1.1 ,2.3 ,3.5 }, {4.1 ,5,6.7} ,{7.9 ,8.1, 90} }";
	std::string input2 = "{{1,1,1},{1,1,1},{1,1,1}}";
	std::string input3 = "{{1,2,3},{4,5,6},{7,8,9},{10,11,12}}";

	matrix *m = new matrix(&input);

	matrix *a = new matrix(&input2);
	
	matrix *b = new matrix(&input3);

	*m = *m + *a;

	m->print_matrix();

	cout << "\n";	

	b->print_matrix();
	
	return 0;	
}
