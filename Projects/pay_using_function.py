def computepay(hrs,rph):

    x=0
    y=0

    if hrs<40:

        GPpay=hrs*rph

        return Gpay

    else:

        x=hrs*rph
        y=(hrs-40)*(rph*0.5)
        Gpay=x+y

        return Gpay

Hrs=input("enter the hours")
Rph=input("enter the rate")

try:
	Hrs=float(Hrs)
	Rph=float(Rph)

except:

    print("enter a numeric value")
    quit()


p=computepay(Hrs,Rph)

print("Pay",p)
