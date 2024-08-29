#include <openssl/bio.h>
#include <openssl/evp.h>
#include <string.h>

void Encode(bool newLine)
{
    BIO *bio, *b64;
    char message[] = "hello, world\n";

    b64 = BIO_new(BIO_f_base64());
    if (!newLine) {
        BIO_set_flags(b64, BIO_FLAGS_BASE64_NO_NL);
    }
    bio = BIO_new_fp(stdout, BIO_NOCLOSE);
    BIO_push(b64, bio);
    BIO_write(b64, message, strlen(message));
    BIO_flush(b64);

    BIO_free_all(b64);
}

int main() 
{
    Encode(true);
    Encode(false);
    return 0;
}