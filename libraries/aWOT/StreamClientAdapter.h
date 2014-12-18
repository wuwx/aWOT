#ifndef StreamClientAdapter_H_
#define StreamClientAdapter_H_

#include <ClientInterface.h>
#include <Arduino.h>

class StreamClientAdapter: public ClientInterface {
public:
	StreamClientAdapter(Stream *stream);
	size_t write(uint8_t b);
	size_t write(const char *str);
	size_t write(const uint8_t *buf, size_t size);
	uint8_t connected();
	int read();
	void flush();
	void stop();
	int available();
	int print(const char* str);
	int println(const char* str);
	int println();
	int print(uint16_t b);
	int println(const int aHeaderValue);
	int read(uint8_t *buf, size_t size);
	int peek();

private:
	Stream *streamPointer;
	virtual inline Stream *stream() {
		return streamPointer;
	}
};

#endif /* StreamClientAdapter_H_ */