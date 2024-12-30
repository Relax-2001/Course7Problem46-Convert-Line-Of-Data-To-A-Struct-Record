#include <iostream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

struct stClient
{
    string AccountNumber = "";
    string PinCode = "";
    string Name = "";
    string Phone = "";
    double AccountBalance = 0;
};

vector <string> SplitString(string UserString , string Delem)
{

    short Pos = 0;
    string Word = "";
    vector <string> vWords;

    while ((Pos = UserString.find(Delem)) != std::string::npos)
    {

        Word = UserString.substr(0 , Pos);

        if (Word != " ")
        {
            vWords.push_back(Word);
        }

        UserString.erase(0, Pos + Delem.length());

    }

    if (UserString != "")
    {
        vWords.push_back(UserString);
    }

    return vWords;
}

stClient ConvertLineToStructure(string Line , string Delem = "#//#")
{

    stClient ClientInfo;
    vector <string> vWords;

    vWords = SplitString(Line , Delem);

    ClientInfo.AccountNumber = vWords[0];
    ClientInfo.PinCode = vWords[1];
    ClientInfo.Name = vWords[2];
    ClientInfo.Phone = vWords[3];
    ClientInfo.AccountBalance = stod(vWords[4]);

    return ClientInfo;
}

void PrintClintInfo(stClient ClientInfo)
{

    cout << "Account Numer = "<< ClientInfo.AccountNumber << "\n";
    cout << "Pin Code = " << ClientInfo.PinCode << "\n";
    cout << "Client name = " << ClientInfo.Name << "\n";
    cout << "Phone number = " << ClientInfo.Phone << "\n";
    cout << "Account balance = " << ClientInfo.AccountBalance << "\n";

}


int main()
{
    string ClientData = "A150#//#1234#//#Mohammed#//#09334421#//#50000";

    stClient Client  = ConvertLineToStructure(ClientData , "#//#");
    PrintClintInfo(Client);

    return 0;
}
