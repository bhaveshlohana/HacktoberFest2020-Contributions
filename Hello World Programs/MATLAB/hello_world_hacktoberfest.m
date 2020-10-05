// hello_world in Objective-C
#import <Foundation/Foundation.h> 
//The Foundation framework contains fundamental classes that are used in all iOS apps and OS X applications.
//#import is faster and more efficient as compared to #include used in c.
int main(int argc, const char * argv[]) {
    @autoreleasepool { //@autoreleasepool creates a scoped area and makes it clearer what’s within the pool. 
		//Inside of the @autoreleasepool block is where we write our code
        NSLog(@"Hello, World!");
		//The next line calls NSLog which is a function brought in by the Foundation Framework. This function is a lot like printf() function in c.
    }
    return 0; //By convention, a return value of zero indicates that the function was successful
}
