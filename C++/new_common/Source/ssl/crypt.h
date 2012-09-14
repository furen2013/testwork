#ifndef _SSL_CRYPT_HEAD
#define _SSL_CRYPT_HEAD

#ifdef __cplusplus
extern "C" {
#endif

void ssl_init_dictionary();

int ssl_encrypt( unsigned char* key, const unsigned char* in_data, int in_len, unsigned char* out_data );

int ssl_decrypt( unsigned char* key, const unsigned char* in_data, int in_len, unsigned char* out_data );

#ifdef __cplusplus
}
#endif

#endif // _SSL_CRYPT_HEAD

