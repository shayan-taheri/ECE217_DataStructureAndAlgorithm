// Data Encryption Standard (DES) Operations in C++ Language
// Instructor: Dr. Shayan (Sean) Taheri

// Driver Code
int main() {
    
  // Task 1: Determine a 64-Bit Key and a 64-Bit Plaintext
  
  // Task 2: Generate 16 Keys for Encryption
  
  // Task 3: Prepare the Keys for Decryption
  
  // Task 4: Use the DES Operations for Encryption and Decryption
  
  // Task 5: Display the Encrypted and the Decrypted Data along with the Original Data

	// A 64 bit key
	string key= "1010101010111011000010010001100000100111001101101100110011011101";
	// A block of plain text of 64 bits
	pt= "1010101111001101111001101010101111001101000100110010010100110110";
	string apt = pt;
	// Calling the function to generate 16 keys
  	generate_keys(key); 
    cout<<"Plain text: "<<pt<<endl; 
	// Applying the algo
    string ct= DES(); 
    cout<<"Ciphertext: "<<ct<<endl;
	// Reversing the round_keys array for decryption
	int i = 15;
	int j = 0;
	while(i > j)
	{
		string temp = round_keys[i];
		round_keys[i] = round_keys[j];
		round_keys[j] = temp;
		i--;
		j++;
	}
	pt = ct;
	string decrypted = DES();
	cout<<"Decrypted text:"<<decrypted<<endl;
	// Comapring the initial plain text with the decrypted text
	if (decrypted == apt){
		cout<<"Plain text encrypted and decrypted successfully."<<endl;
	}
}