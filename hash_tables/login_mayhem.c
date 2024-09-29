#define MAX_USERS 100000
#define MAX_PASSWORD 10

int main(void) {
    static char users[MAX_USERS][MAX_PASSWORD + 1];
    int num_ops, op, op_type, total, j;
    char password[MAX_PASSWORD + 1];
    int num_users = 0;
    scanf("%d", &num_ops);
    for (op=0;op<num_ops;op++) {
        scanf("%d%s", &op_type, &password);

        if (op_type==1) {
            strcpy(users[num_users], password);
            num_users++;
        } else {
            total = 0;
            for (j=0;j<num_users;j++)
                if (strstr(users[j], password))
                    total++;
            printf("%d\n", total);

        }
    }
    return 0;
}