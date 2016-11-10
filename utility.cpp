

//calculate two bytes CRC
int calcCRC(const char * crcStartPtr, int  buffLen)
{
	int crc = 0xFFFF;
	char * bufferTop = crcStartPtr + buffLen;
	char * crcBuffPtr = crcStartPtr; 
	int  i;

	while (crcBuffPtr < bufferTop)
	{
		crc = (int)(crc & 0xff00) + (*(char *)crcBuffPtr ^ LOBYTE(crc));
		for (i = 0; i<8; i++)
		{
			if ((crc & 0x0001) == TRUE)
				crc = (crc >> 1) ^ 0xA001;
			else
				crc = (crc >> 1);
		}
		crcBuffPtr++;
	}
	return (crc);
} 
