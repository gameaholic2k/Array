#include  <iostream>
#include  "Array.h"

using  namespace  std;


typedef  double  ELEMENT_TYPE;

#define LAST_INDEX_VALUE data.getLength() + data.getStartIndex() - 1

//
// Tests for arrays with the default start index of zero.
//
void  zeroBasedArrayTest()
{
	Array<ELEMENT_TYPE>  data(6);
	data[0] = 10;
	data[1] = 10;
	data[2] = 20;
	data[3] = 10;
	data[4] = 10;
	data[5] = 30;

	cout << std::endl
		<< "Zero based - "
		<< data[0] << ' '
		<< data[1] << ' '
		<< data[2] << ' '
		<< data[3] << ' '
		<< data[4] << ' '
		<< data[5] << ' '
		<< std::endl;
}

//
// Tests for arrays with the default start index of
// an integer greater than 0.
//
void  positiveBasedArrayTest()
{
	Array<ELEMENT_TYPE>  data(10, 5);

	data[5]  = -10;
	data[6]  = -20;
	data[7]  = -30;
	data[8]  = -40;
	data[9]  = -50;
	data[10] = -60;

	cout << std::endl
		<< "Positive - "
		<< data[5] << ' '
		<< data[6] << ' '
		<< data[7] << ' '
		<< data[8] << ' '
		<< data[9] << ' '
		<< data[10] << ' '
		<< std::endl;
}


//
// Tests for arrays with the default start index of
// an integer less than 0.
//
void  negativeBasedArrayTest()
{
	Array<ELEMENT_TYPE>  data(6, -2);

	data[-2] = -20;
	data[-1] = -10;
	data[0] = 0;
	data[1] = 1;
	data[2] = 2;
	data[3] = 3;

	cout << std::endl
		<< "Negative - "
		<< data[-2] << ' '
		<< data[-1] << ' '
		<< data[0] << ' '
		<< data[1] << ' '
		<< data[2] << ' '
		<< data[3] << ' '
		<< std::endl;
}



//
// Test the copy constructor for the Array class.
//

void  copyTest()
{
	const int  start_index = 7;
	const int  length = 10;

	Array<ELEMENT_TYPE>  data(length, start_index);

	for (int idx = start_index; idx < length + start_index; ++idx)
		data[idx] = idx - start_index;

	cout << std::endl << "Original" << std::endl;
	for (int idx = data.getStartIndex(); idx < data.getLength() + data.getStartIndex(); ++idx)
		cout << data[idx] << ' ';
	cout << endl << endl;


	// Copy constructor test
	Array<ELEMENT_TYPE>  cctor(data);
	Array<ELEMENT_TYPE>  cctor2(data);
	
	cout << std::endl << "cctor" << std::endl;
	for (int idx = cctor.getStartIndex(); idx < cctor.getLength() + cctor.getStartIndex(); ++idx)
		cout << cctor[idx] << ' ';
	cout << endl << endl;

	cout << std::endl << "cctor2" << std::endl;
	for (int idx = cctor2.getStartIndex(); idx < cctor2.getLength() + cctor2.getStartIndex(); ++idx)
		cout << cctor2[idx] << ' ';
	cout << endl << endl;


	//Assignment operator test
	Array<ELEMENT_TYPE> assignCopy = data;
	cout << std::endl << "assignCopy" << std::endl;
	for (int idx = assignCopy.getStartIndex(); idx < assignCopy.getLength() + assignCopy.getStartIndex(); ++idx)
		cout << assignCopy[idx] << ' ';
	cout << endl << endl;


	Array<ELEMENT_TYPE>  other(1, 0);
	other = data;
	cout << std::endl << "other" << std::endl;
	for (int idx = other.getStartIndex(); idx < other.getLength() + other.getStartIndex(); ++idx)
		cout << other[idx] << ' ';
	cout << endl << endl;

	//Self assignment operator test
	data = data;
	cout << std::endl << "Original" << std::endl;
	for (int idx = data.getStartIndex(); idx < data.getLength() + data.getStartIndex(); ++idx)
		cout << data[idx] << ' ';
	cout << endl << endl;
}

void modifyArrayTest()
{
	const int  start_index = 7;
	const int  length = 10;
	Array<ELEMENT_TYPE>  data(length, start_index);

	for (int idx = start_index; idx < length + start_index; ++idx)
		data[idx] = idx - start_index;

	cout << std::endl << "Original" << std::endl;
	for (int idx = data.getStartIndex(); idx < data.getLength() + data.getStartIndex(); ++idx)
		cout << data[idx] << ' ';
	cout << endl << endl;

	cout << "Original start index: " << data.getStartIndex() << endl;
	cout << "Original start index value: " << data[7] << endl << endl;

	const int new_index = 10;
	data.setStartIndex(new_index);

	cout << "New start index: " << data.getStartIndex() << endl;
	cout << "New start index value: " << data[new_index] << endl << endl;

	cout << "Original length: " << data.getLength() << endl;
	cout << "Original last index value: " << data[LAST_INDEX_VALUE] << endl << endl;

	data.setLength(5);

	cout << std::endl << "Resized" << std::endl;
	cout << std::endl << "Original" << std::endl;
	for (int idx = data.getStartIndex(); idx < data.getLength() + data.getStartIndex(); ++idx)
		cout << data[idx] << ' ';
	cout << endl << endl;

	cout << "New length: " << data.getLength() << endl;
	cout << "New last index value: " << data[LAST_INDEX_VALUE] << endl << endl;



}

//
// main() program
//
int  main()
{
	zeroBasedArrayTest();
	positiveBasedArrayTest();
	negativeBasedArrayTest();
	copyTest();
	modifyArrayTest();


	return  0;
}