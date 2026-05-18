#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct position
{
    int x;
    int y;
};

struct packet
{
    int protocol_id; // 0 (alert) ou 1 (position)
    union
    {
        char alert_msg[32];
        struct position position;
    } data;
};
typedef struct packet Packet;

int save_packet(Packet *p)
{
    if (p == NULL)
        return -1;
    FILE *out = fopen("data.bin", "wb");
    if (out == NULL)
        return -1;

    fwrite(p, sizeof(Packet), 1, out);
    fclose(out);
    return 0;
}

int main()
{
    Packet *p = malloc(sizeof(Packet));
    p->protocol_id = 1;
    struct position pos;
    pos.x = 145;
    pos.y = 20;

    p->data.position = pos;

    save_packet(p);
    free(p);

    // Lecture
    FILE *in = fopen("data.bin", "rb");
    if (in == NULL)
        return 1;

    Packet *read_p = malloc(sizeof(Packet));

    if (read_p == NULL)
    {
        fclose(in);
        return 1;
    }

    fread(read_p, sizeof(Packet), 1, in);
    printf("Type de lecture : %d\n", read_p->protocol_id);
    switch (read_p->protocol_id) {
        case 1:
            printf("Position : (%d,%d)\n", read_p->data.position.x, read_p->data.position.y);
            break;
        default:
            printf("Message : %s\n", read_p->data.alert_msg);
            break;
    }

    free(read_p);
    fclose(in);
    return 0;

}