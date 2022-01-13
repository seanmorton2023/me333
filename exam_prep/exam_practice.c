
/*
structs
compilation processes
strings in C
arrays in C
pointer notation
user i/o
integer overflow
memory allocation of variables in the stack


*/



typedef struct {
	int id;
	char name[100];

} record;

record r;

r.id = 5;
r.name = "Bob Seger";


//the other way Nick recommended: use sprintf() to write to
//a string, or to write into a variable.
sprintf(r.name,"%s/n","My new record name");

//what if we wanted to get the name from user?
printf("Type the name\n");

//can use intermediate step to get name first
char m[100];
scanf("%s\n",m); //name of an array works as a pointers

//saying r.name = m doesn't work, as both of those things are pointers
//and we can't put the contents of one in another
//a better way to do this is to use string.h library, do strcpy()


printf("Type in the id\n");
scanf("%d\n",&r.id);

//with int types, you can also copy values in with no pointers involved
r.id = 5;


//the more proper way to refer to structs in C is to
//use pointers - string assignment works using pointers,
//so we should respect that. when we have pointers we use arrows
record *rp;
rp->id = 6;
rp->name = "My record"; //Nick isn't sure if this will work but
						//he says as long as you haven't defined rp->name
						//this should work perfectly; if you change the name
						//after you may have to do it elementwise. r.name[0] = 's',
						//r.name[1] = 'e', r.name[2] = 'a',...

//remember we can make intermediate functions to do things
int getid2(void){
	int n; //temp 
	scanf("%d\n",&n);
	return n;
}

//with pointers, you take in the pointer and modify by reference
void getid3(record *rp) {
	scanf("%d\n", &rp->id); //rp->id is the value so we still need the mem address (&)
}

//an array name acts as a pointer, so this is simple for strings
void getname2(record *rp) {
	scanf("%s\n", rp->name);
}

//another question nick likes: draw the memory stack and show what
//happens when you do something
int i = 4;
char m = 'w';

//draw the stack and say:
//what is the mem address &i?
//what is the mem address &w?     
