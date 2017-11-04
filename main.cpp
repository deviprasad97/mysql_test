#include<iostream>
#include<mysql.h>
#include<stdlib.h>
#include<stdio.h>
int main(){
  MYSQL *conn= mysql_init(NULL);
  MYSQL_RES *res; /* holds the result set */
  MYSQL_ROW row;
  std::string e_password = "pass";
  if(mysql_real_connect(conn, "35.193.124.76", "ice", "00000000", "ice", 0, NULL, 0)){
    char q[1000];
    //sprintf(q, "insert into user(id,u_name,password,type) values('2','siddhart', 'pass', '1')");
    mysql_query(conn, "select password FROM user where u_name='devi'");
    res = mysql_store_result(conn);
    int num_fields = mysql_num_fields(res);
    if((row=mysql_fetch_row(res))){
      for(int i = 0; i < num_fields; i++)
      {
               std::string password = row[i];
               if(e_password==password){
                 std::cout << "Your are logged in" << std::endl;
               }else{
                 std::cout<<"Invalid password";
               }

      }
    }else{
      std::cout<<"Invalid Username\n";
    }
    while ((row = mysql_fetch_row(res)))
    {
       // Print all columns
       for(int i = 0; i < num_fields; i++)
       {
           // Make sure row[i] is valid!
                char *val = row[i];

                  std::cout << row[i] << std::endl;


           // Also, you can use ternary operator here instead of if-else
           // cout << row[i] ? row[i] : "NULL" << endl;
       }
    }
  }
  mysql_close(conn);
  return 0;
}
