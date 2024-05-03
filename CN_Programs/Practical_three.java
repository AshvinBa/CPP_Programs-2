//Program : Implementation of XOR Symmetric Cryptographic Algorithm
import java.io.*;
import java.lang.String;
public class Xor4
{
public static voidmain(String args[])
{
String Msg = "SSBTCOETJALGAON";
char Key='$';
String CTxt="";
String DTxt="";
int xor,xor1;
chartemp,temp1;
for(int i=0;i<Msg.length();i++ )
{
xor=Msg.charAt(i) ^ Key;
temp =(char)xor ;
CTxt=CTxt + temp;
}
System.out.println("Encryption and Decryption using XOR Cryptogrpahy");
System.out.println("Original Message is:" +Msg);
System.out.println("Encrypted Message is:" +CTxt);
for(int i=0;i<CTxt.length();i++)
{
xor1=CTxt.charAt(i)^ Key;
temp1 =(char) xor1;
DTxt=DTxt+ temp1;
}
System.out.println("Decrypted Message is:"+DTxt);
}
}