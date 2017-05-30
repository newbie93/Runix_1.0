#include "keyboard.h"

KeyboardDriver::KeyboardDriver(InterruptManager* manager)
: InterruptHandler(manager, 0x21),
dataport(0x60),
commandport(0x64)
{
    while(commandport.Read() & 0x1)
        dataport.Read();
    commandport.Write(0xae); // activate interrupts
    commandport.Write(0x20); // command 0x20 = read controller command byte
    uint8_t status = (dataport.Read() | 1) & ~0x10;
    commandport.Write(0x60); // command 0x60 = set controller command byte
    dataport.Write(status);
    dataport.Write(0xf4);
}

KeyboardDriver::~KeyboardDriver()
{
}

void print_screen(char*);

uint32_t KeyboardDriver::HandleInterrupt(uint32_t esp)
{
	
	static bool shift=false,caps=false;
	
    uint8_t key = dataport.Read();
    if(key < 0x80)
    {
		
        switch(key)
        {
			/*Shift*/
			
			case 0x3A:
				if(caps==false)
					caps=true;
				else
					caps=false;
				break;
						
			
			/*Numbers*/	
					
            case 0x02:
				if(shift==false)
					print_screen("1"); 
				else
					print_screen("!"); 
				break;
				
				
            case 0x03:
				if(shift==false)
					print_screen("2"); 
				else
					print_screen("@"); 
				break;
					
            case 0x04:
				if(shift==false)
					print_screen("3"); 
				else
					print_screen("#"); 
				break;
				
					
            case 0x05:
				if(shift==false)
					print_screen("4"); 
				else
					print_screen("$"); 
				break;
				
					
            case 0x06:
				if(shift==false)
					print_screen("5"); 
				else
					print_screen("%"); 
				break;
				
					
            case 0x07:
				if(shift==false)
					print_screen("6"); 
				else
					print_screen("^"); 
				break;
					
            case 0x08:
				if(shift==false)
					print_screen("7"); 
				else
					print_screen("&"); 
				break;
					
            case 0x09:
				if(shift==false)
					print_screen("8"); 
				else
					print_screen("*"); 
				break;
					
            case 0x0A:
				if(shift==false)
					print_screen("9"); 
				else
					print_screen("("); 
				break;
					
            case 0x0B:
				if(shift==false)
					print_screen("0"); 
				else
					print_screen(")"); 
				break;
					
            case 0x0C:
				if(shift==false)
					print_screen("-"); 
				else
					print_screen("_"); 
				break;
					
            case 0x0D:
				if(shift==false)
					print_screen("="); 
				else
					print_screen("+"); 
				break;
				
				
			/*Alphabets*/
			
			case 0x1E:
				if(shift==false && caps==false)
					print_screen("a"); 
				else
					print_screen("A"); 
				break;
				
			case 0x30:
				if(shift==false && caps==false)
					print_screen("b"); 
				else
					print_screen("B"); 
				break;
				
			case 0x2E:
				if(shift==false && caps==false)
					print_screen("c"); 
				else
					print_screen("C"); 
				break;
				
			case 0x20:
				if(shift==false && caps==false)
					print_screen("d"); 
				else
					print_screen("D"); 
				break;
				
			case 0x12:
				if(shift==false && caps==false)
					print_screen("e"); 
				else
					print_screen("E"); 
				break;
				
			case 0x21:
				if(shift==false && caps==false)
					print_screen("f"); 
				else
					print_screen("F"); 
				break;
				
			case 0x22:
				if(shift==false && caps==false)
					print_screen("g"); 
				else
					print_screen("G"); 
				break;
				
			case 0x23:
				if(shift==false && caps==false)
					print_screen("h"); 
				else
					print_screen("H"); 
				break;
				
			case 0x17:
				if(shift==false && caps==false)
					print_screen("i"); 
				else
					print_screen("I"); 
				break;
				
			case 0x24:
				if(shift==false && caps==false)
					print_screen("j"); 
				else
					print_screen("J"); 
				break;
				
			case 0x25:
				if(shift==false && caps==false)
					print_screen("k"); 
				else
					print_screen("K"); 
				break;
				
			case 0x26:
				if(shift==false && caps==false)
					print_screen("l"); 
				else
					print_screen("L"); 
				break;
				
			case 0x32:
				if(shift==false && caps==false)
					print_screen("m"); 
				else
					print_screen("M"); 
				break;
				
			case 0x31:
				if(shift==false && caps==false)
					print_screen("n"); 
				else
					print_screen("N"); 
				break;
				
			case 0x18:
				if(shift==false && caps==false)
					print_screen("o"); 
				else
					print_screen("O"); 
				break;
				
			case 0x19:
				if(shift==false && caps==false)
					print_screen("p"); 
				else
					print_screen("P"); 
				break;
				
			case 0x10:
				if(shift==false && caps==false)
					print_screen("q"); 
				else
					print_screen("Q"); 
				break;
				
			case 0x13:
				if(shift==false && caps==false)
					print_screen("r"); 
				else
					print_screen("R"); 
				break;
				
			case 0x1F:
				if(shift==false && caps==false)
					print_screen("s"); 
				else
					print_screen("S"); 
				break;
				
			case 0x14:
				if(shift==false && caps==false)
					print_screen("t"); 
				else
					print_screen("T"); 
				break;
				
			case 0x16:
				if(shift==false && caps==false)
					print_screen("u"); 
				else
					print_screen("U"); 
				break;
				
			case 0x2F:
				if(shift==false && caps==false)
					print_screen("v"); 
				else
					print_screen("V"); 
				break;
				
			case 0x11:
				if(shift==false && caps==false)
					print_screen("w"); 
				else
					print_screen("W"); 
				break;
				
			case 0x2D:
				if(shift==false && caps==false)
					print_screen("x"); 
				else
					print_screen("X"); 
				break;
				
			case 0x15:
				if(shift==false && caps==false)
					print_screen("y"); 
				else
					print_screen("Y"); 
				break;
				
			case 0x2C:
				if(shift==false && caps==false)
					print_screen("z"); 
				else
					print_screen("Z"); 
				break;
			
			
			
			/*Enter*/
			case 0x1C:
					print_screen("\n");
					break;
			
			/*Space*/
			case 0x39:
					print_screen(" ");
					break;
			
			

            default:
            {
                char* foo = "KEYBOARD 0x00 ";
                char* hex = "0123456789ABCDEF";
                foo[11] = hex[(key >> 4) & 0xF];
                foo[12] = hex[key & 0xF];
                print_screen(foo);
                break;
            }
        }
    }
    return esp;
}
