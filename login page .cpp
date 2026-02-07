# include <iostream>
# include <fstream>
using namespace std ;

class temp{
    string UserName,Email,Password;
    string searchName,searchPassword,searchEmail;
    fstream file;
    public:
    void Login();
    void SingnUp();
    void Forget();

}obj;
void temp ::SingnUp()
{
  cout<<"\nEnter your User name : ";
  getline(cin,UserName);
  cout<<"\nEnter your Email Address : ";
  getline(cin,Email);
  cout<<"\nEnter your Password : ";
  getline(cin,Password);
  
  file.open("logindata.txt",ios :: out |ios :: app);
  file<<UserName<<"*"<<Email<<"*"<<Password<<endl;
  file.close();
}
void temp :: Login()
{
    cout<<"------Login------"<<endl;
    cout<<"\nEnter your User name : ";
    getline(cin,searchName);
    cout<<"\nEnter your Password : ";
    getline(cin,searchPassword);
    cout<<"\nEnter your Email: ";
    getline(cin,searchEmail);
    
    file.open("\nlogindata.txt",ios :: in);
    getline(file,UserName,'*');
    getline(file,Email,'*');
    getline(file,Password,'\n');
    while(!file.eof())
    {
      if(UserName == searchName&&Email==searchEmail&&Password==searchPassword)
      {
            cout<<"\nAccount Login Sucessfully..."<<endl;
            cout<<"\nUserName:"<<UserName<<endl;
            cout<<"\nEmail:"<<Email<<endl;
            break;
      }
      else
      {
        cout<<"\nPassword Incorrect!!!"<<endl;
        break;
      }
    getline(file,UserName,'*');
    getline(file,Email,'*');
    getline(file,Password,'\n');
    }
 file.close();
}
void temp :: Forget()
{
  cout<<"\nEnter your User name : ";
  getline(cin,searchName);
  cout<<"\nEnter your Email Address : ";
  getline(cin,searchEmail);
  file.open("\nlogindata.txt",ios :: in);
  getline(file,UserName,'*');
  getline(file,Email,'*');
  getline(file,Password,'\n');
   while(!file.eof())
    {
      if(UserName == searchName&&Email==searchEmail)
      {
       
            cout<<"\nAccount Found..."<<endl;
            cout<<"\nYour Password"<<Password<<endl;
            break;
      }
       else{
            cout<<"\nNot Found..!"<<endl;
            break;
         }
    }
   file.close();
}



int main ()
{
    char choice = 0;
    while (choice != '4') 
{
    cout<<"\n1.Login "; 
    cout<<"\n2. Sign up";
    cout<<"\n3.Forgot Password";
    cout<<"\n4.Exit ";
    cout<<"\nEnter your choice:";
    cin>>choice;
    cin.ignore();
    switch (choice)
    {
    case '1':
        obj.Login();
        break;
    case '2':
        obj.SingnUp();
        break;    
    case '3':
        obj.Forget();
        break;
    case '4':
        return 0;
        break;    
    default:
            cout<<"Invalid Details!!";
        break;
    } 
  }
}
