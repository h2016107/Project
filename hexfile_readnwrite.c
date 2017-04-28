#include <stdio.h>
#define MAXHEXLINE 32 
void remove_char( uint8_t * charter, int * charsum)
{
	while (*charter == '\n' || *charter == '\r' || *charter ==':')
	{
		(*charter = fgetc (file));
		*charsum++;
	}
}

uint8_t asciitohex(uint8_t d)
{
	if (d >= '0' && d <= '9')
	{
		return (uint8_t)(d - '0');
	}
	if (d >= 'A' && d <= 'F')
	{
		return (uint8_t)(d - 'A' + 10);
	}
	if (d >= 'a' && d <= 'f')
	{
        return (uint8_t)(d - 'a' + 10);
	}

	return 0; 
}

int line_count(FILE * count)
{
	int line_count = 0;
	char end_value;

	while(end_value != EOF)
	{
		got_char = fgetc(count);
		if (got_char == ':')
{count++;
}
	}
	rewind(count);
	return count;
}

uint8_t read_byte(uint8_t * charter, int * charsum)
{
	//Holding the combined nibbles.
	uint8_t hexVal;
	//Get first nibble.
	*charter = fgetc (file);
	remove_char( char_to_put, total_chars_read);
	//place the  first nibble.
	hexVal = (asciitohex(*charter));
	//Slide the nibble.
	hexVal = ((hexValue << 4) & 0xF0);
	//place the second nibble .
	*charter = fgetc (file);
	remove_char( charter, charsum);
	//combine the nibbles together.
	hexValue |= (Hextoascii(*charter));
    *charsum += 2;
    return hexValue;
}

bool read_line( uint8_t line_data [], long int * net_address, int * bytes_line)
{
		int data = 0;
		uint8_t charter;
		int charsum = 0;

		//To hold file hex values.
		uint8_t byte_count;
		uint8_t dat_address1;
		uint8_t dat_address2;
		uint8_t dat_record_type;
		uint8_t dat_check_sum;

		//BYTE COUNT
		byte_count = read_byte( &charter, &charsum);

		// No need to read, if no data.
		if (byte_count == 0)
		{return false;
		    }
        dat_address1 = read_byte( &charter, &charsum);
        dat_address2 = read_byte( &charter, &charsum);
        dat_record_type = read_byte( &charter, &charsum);		
        
        if (datum_record_type != 0)
		{return false;
		    
		}
        *net_address = ((uint16_t)dat_address1 << 8) | dat_address2;

		// data in the line
		while(data < byte_count)
		{
			line_data[data_index] = read_byte( &charter, &charsum);
			data++;
		}			
		*bytes__line = data;

		// CHECKSUM.....total sum of data
		dat_check_sum = read_byte( &charter, &charsum);
        return true;
}

void hexout_data(fhex, byte, memory_locat, end)
FILE *fhex;  /* the file to put intel hex into */
int byte, memory_locat, end;
{
	static int byte_buffer[MAXHEXLINE];
	static int last_memory, buffer_position, buffer_addrress;
	static int writing_in_progress=0;
	register int i, sum;

	if (!writing_in_progress) {
		/* initial condition setup */
		last_mem = memory_locat-1;
		buffer_position = 0;
		buffer_address = memory_locat;
		writing_in_progress = 1;
		}

	if ( (memory_location != (last_mem+1)) || (buffer_position >= MAXHEXLINE) \
	 || ((end) && (buffer_position > 0)) ) {
		/* it's time to dump the buffer to a line in the file */
		fprintf(fhex, ":%02X%04X00", buffer_pos, buffer_address);
		sum = buffer_position + ((buffer_address>>8)&255) + (buffer_address&255);
		for (i=0; i < buffer_position; i++) {
			fprintf(fhex, "%02X", byte_buffer[i]&255);
			sum += byte_buffer[i]&255;
		}
		fprintf(fhex, "%02X\n", (-sum)&255);
		buffer_addr = memory_location;
		buffer_pos = 0;
	}

	if (end) {
		fprintf(fhex, ":00000001FF\n");  /* end of file marker */
		fclose(fhex);
		writing_in_progress = 0;
	}
		
	last_mem = memory_location;
	byte_buffer[buffer_position] = byte & 255;
	buffer_position++;
}

void load_file(filename)
{
    char *filename;
	char line[1000];
	FILE *file;
	int net_address,bytes_line,bytes[256];
	int i, total=0, lineno=1;
	int minaddress=65536, maxaddress=0;

	if (strlen(filename) == 0) {
		printf("   Can't load a file without the filename.");
		return;
	}
	file = fopen(filename, "r");
	if (file == NULL) {
		printf("   Can't open file '%s' for reading.\n", filename);
		return;
	}
	while (!feof(file) && !ferror(file))
	{
		if ( read_line(  bytes [],  * net_address, int * bytes_line) {
			 /* data */
				for(i=0; i<=; i++) {
					memory[net_address] = bytes[i] & 255;
					total++;
					if (net_address < minaddress) minaddress = net_address;
					if (net_address > maxaddress) maxaddress = net_address;
					netaddress++;
				
				}
				
				void hexout_data(file, bytes, net_address,end);
			}
		else
		
			printf("no data");
			
		} 
		
}

void main()
{
    
     load_file(filename); // for reading ihex file and writing to other hex file
        
    
}





	
	
