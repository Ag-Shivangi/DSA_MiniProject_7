# DSA_MiniProject_7
**************************************************************************************************************
                      FRIEND RECOMMENDATION SYSTEM
**************************************************************************************************************
GROUP 7

Venika Sruthi (2020101072)
Shavak Kansal (2020101023)
Shivangi Agarwal (2020113011)
Venneti Sri Satya Vinay (2020101066)
Manaswini Tharigopula(2020113015)
**************************************************************************************************************

                        COMPILE INSTRUCTIONS
                       **********************

Link math and crypt while compiling the main file:
    gcc main.c -lm -lcrypt

The following libraries are included
<stdio.h>
<string.h>
<stdlib.h>
<stdbool.h>
<math.h>
<ctype.h>
<limits.h>
<unistd.h>
<crypt.h>

Some of the libraries (unistd.h and crypt.h) work only on linux.
**************************************************************************************************************
When you run the code, It will display a menu.
Enter an integer according to your choice. If you Enter

1. The program asks you for user information and registers user in the system.
   The following details are asked: name,city,birthday, password and hobbies.
   The name has to be atleast 4 characters and a maximum of 29 characters. 
   The city has to be atleast 2 characters and a maximum of 29 characters.
   The hobbies have to entered separated by commas (Eg: 1,2,6)
   The program returns an user ID.
   (The data is stored in a dynamic array and the password is encrypted using MD5 algorithm and stored)

2. The program lets you login using your user ID and password. It then asks you to choose from a menu
        1. Add Friend : Takes user ID and adds friend if ID exists
        2. Remove Friend : Takes user ID and removes from friend array
        3. Check Friendlist : Displays Friends and details
        4. Look Up User : Takes user id and displays details if exists
        5. Check Recommendation : Displays all users with mutual friends(or hobbies if friends dont exist)
        6. Log Out : Takes you back to the main menu
        7. Delete Account : Removes user from the system and goes back to the main menu

3. Takes two user ids and tells if the first user has added the 2nd user as a friend.
4. Exits program .

**************************************************************************************************************
