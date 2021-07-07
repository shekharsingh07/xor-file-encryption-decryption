#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int main()
{
    char c;
    // Assumming that "message.xor" is in the same root folder
    ifstream message;
	//string receivedMessage = "message.xor";
	string receivedMessage;
	cout << "Please enter the file name or file path to be encrypted/decrypted:\n";		//type the file name if it's in the root folder as the programme, else type the file path
	getline(cin, receivedMessage);
    message.open(receivedMessage.c_str());								//Opening the message and converting to str
	cout << "The message is being encrypted/decrypted...\n";
	
	// The output text file will be created if it doesn't exist
    ofstream decryptedMessage;
    //string transferredMessage = "Message.txt";
    string transferredMessage;
    cout<<endl;
    cout << "Please enter the file name in which to store the data: \n";
    getline(cin, transferredMessage);
    cout<<"The encrypted/decrypted data can be found in "<<transferredMessage<<".\n";
    decryptedMessage.open(transferredMessage.c_str());					//opening the target file "outputMessage.txt"
    
    

    //PART 1: Putting the KEY into an array ---------------------------

    string key;
    cout<<"\n\nPlease input the KEY for the encryption/decryption (including no spaces/blanks):";
    cin>>key;
        
    int keyLen; // number of characters of the key
    keyLen = key.length();

    char key_array[32];
    for(int i=0; i<keyLen; i++)
    {
        key_array[i] = key[i];
    }

    // END PART 1 ---------------------------------------------------------


    char input_array[32];
    char output_array[32];

    while(!message.eof())
    {


    // PART 2: Putting the encrypted message into an array ----------------
    
    int j=0;
    while(!message.eof() && j<keyLen)
    {
        message.get(c);
        input_array[j] = c;
        j++;
        if(message.eof())
            keyLen = j;
    }

        
    // END PART 2 ----------------------------------------------------------


    // PART 3: Encrypting/Decrypting and putting it into an array-----------

    for(int k=0; k<keyLen; k++)
    {
        output_array[k] = input_array[k] ^ key_array[k];
        decryptedMessage.put(output_array[k]);					//Putting the encrypted/decrypted message in the target file
		cout<< output_array[k];									//Printing the output message
    }

    // END PART 3 ----------------------------------------------------------

    }
    

    return 0;
}
