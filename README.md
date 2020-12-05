# Car-rental-system      
_____________________________________________________________________________________
Goal:
A platform which will provide a gateway for car owners aiming to rent out their cars to potential customers who are looking to rent cars for a certain amount of time.

Description:
There are 3 main users in the application. The car owner, the admin and the customer. The admin will act as a middle man between the car owner and the customer, and its task will be to verify both parties involved and to handle all the logistics involved between them. 

Actors/System User(s):
1.	Admin.
2.	Car Owner.
3.	Customer.

List of Features:
1.	CAR OWNER:  
      •	Account to login if he is already registered, otherwise signup with ID and password.
      •	Vehicle documentation papers and information.
      •	Time duration regarding availability of vehicle.
      •	Payment will be transferred to Car Owner by Admin after Admin’s commission deduction.


2.	ADMIN:
      •	Login and password required. 
      •	Can view all details regarding Car Owner, Vehicle and User.
      •	Will get Money from Customer and transfer to Car Owner after keeping commission.
      •	Will implement the car owner’s vehicle conditions.
      •	Can edit and access everything except confidential information.
      •	Will act as an intermediary between Car Owner and User.


3.    USER:
      •	Will register and provide information for first time, otherwise log in and password.
      •	Time when car checked out
      •	Modes of booking. 
            A.	Emergency booking
            B.	Normal booking 
      •	Will specify time for booking, if time is above a certain period, discounts will be provided accordingly.
      •	Modes of payment. Card or Cash.
      •	Print receipt whose details will be passed along to admin and car owner.


Tools & Techniques:
The language used will be C and for IDE Visual Studio 2019 will primarily be used. Filing will be used in order to store the data.

