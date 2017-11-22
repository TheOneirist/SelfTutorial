void Func4(int* pArray, int sizeArr, int* run, int* freq) {

	int greatestRun = 0;
	int greatestFreq = 0;
	int necSize = sizeArr;

	_asm {
		push ebx
		mov ecx, sizeArr //want to compare each element against entire array
		mov esi, pArray	//get address of array into esi

		runFind:
			mov edx, [esi] //get element at address of esi into edx
			
			push ecx		 //comparing against array, saving for outer loop
			mov ecx, necSize //each element in, you need to iterate one less
			mov edi, esi	 //get current index of array

			compare:
				mov ebx, 0 //used to keep track of current streak
				mov eax, [edi] //get second for loop's element at index
				cmp eax, edx   //compare element against second for loop's
				je run
				//if not equal, run is broken
				mov ecx, 0	//want to stop looping
				cmp ebx, greatestFreq //see if I set a new record
				jl run
				//did set a new record, want to record stats
				mov greatestFreq, ebx
				mov greatestRun, edx

				run:
					inc ebx
					add edi, 4

			loop compare
			dec necSize
			pop ecx

			add esi, 4

		loop runFind

		pop ebx
	}
}




/* //int Func3(int* pArray, int sizeArr){
_asm

lea esi, pArray
mov eax, [esi]
add pArray, 4
mov ecx, sizeArr
dec ecx //first element is initial largest

greatestLoop:
cmp eax, [esi]
jg skip
mov eax, [esi]
add pArray, 4
skip:
loop greatestLoop
}



.586
.model flat, c
.stack
.data

.code

func1 proc
mov ecx, sizeArr
mov eax, 0

arrAddLoop:
add eax, [pArray]
add pArray, 4

loop arrAddLoop

func1 endp
end

*/