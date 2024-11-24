#include <stdio.h>
#include <math.h>

int fact(int x)
{
    if (x == 0 || x == 1)
        return 1;
    else
        return x * fact(x - 1);
}

float root(float x, float r)
{
    float sum = 0;
    float result;
    float f;
    float s;
    for (int i = 0; i < 15; i++)
    {
        if (i == 0)
            result = 1;
        else if (i != 0)
        {
            if (i == 1)
                s = r;
            else if (i > 1)
            {
                s = s * (r - (i - 1));
            }
            f = fact(i);
            result = (float)(s * (pow(x, i))) / f;
        }

        sum = result + sum;
    }
    sum = (pow(((float)1 / x), r)) * (sum);
    return sum;
}

float epoww(float x)
{
    float sum = 0;
    for (int i = 0; i < 154; i++)
    {
        float res;
        res = pow(x, i) / fact(i);
        sum = sum + res;
    }

    return sum;
}
float sinn(float x)
{
    x = x * ((3.141592654) / (180));
    float res, sum;
    for (int i = 0; i < 15; i++)
    {
        res = pow((-1), i) * ((pow(x, ((2 * i) + 1))) / (fact((2 * i + 1))));
        sum = sum + res;
    }

    return sum;
}

float coss(float x)
{
    x = x * ((3.141592654) / (180));

    float res, sum;
    for (int i = 0; i < 15; i++)
    {
        res = pow((-1), i) * ((pow(x, (2 * i))) / (fact((2 * i))));
        sum = sum + res;
    }

    return sum;
}
float lnn(float x)
{
    float sum;
    float s = x;
    if (s == 1)
        sum = 0;
    else if (x > 1)
    {
        float res;
        x = x - 1;
        x = (float)1.00 / x;
        for (int i = 1; i < 47; i++)
        {
            res = pow((-1), (i - 1)) * ((pow(x, (i)))) / (i);
            sum = sum + res;
        }

        if ((s - 1) > 0)
            sum = sum + lnn(s - 1);
    }
    return sum;
    printf("%f", sum);
}
float tann(float x)
{
    float s = x;

    float res, sum;
    if (x > 1)
    {
        x = (float)1.00 / x;

        for (int i = 0; i < 35; i++)
        {
            res = pow((-1), i) * ((pow(x, ((2 * i) + 1))) / ((2 * i) + 1));
            sum = sum + res;
        }
        sum = ((3.141592654) / (2)) - sum;
        // sum = 90 - sum;
    }
    else if (s < 1)
    {
        sum = 0;
        for (int i = 0; i < 35; i++)
        {
            res = pow((-1), i) * ((pow(x, ((2 * i) + 1))) / ((2 * i) + 1));
            sum = sum + res;
        }
    }

    sum = sum * ((180) / (3.141592654));
    if (s < 0)
        sum = -sum;
    return sum;
}
int main(void)
{

    int operation;

    printf("0.Exit");
    printf("\n");
    float res;
    do
    {
        printf("1.The nth root of any number\n");
        printf("2.Sin value of any angle\n");
        printf("3.Cos value of any angle\n");
        printf("4.value of e power any number\n");
        printf("5.value of number inside the Ln \n");
        printf("6.value of number inside the ArcTan \n");
        scanf("%d", &operation);

        switch (operation)
        {
        case 1:
        {
            float r;
            float x;
            printf("Enter the degree of the root you want to compute >>>> ");
            scanf("%f", &r);
            r = (float)1.00 / r;
            printf("Enter a positive number less than 1 that you want to find its root >>>>>> ");
            scanf("%f", &x);
            x = x - 1;
            x = (float)1.00 / x;
            res = root(x, r);
            printf("\n%f\n", res);
            break;
        }

        case 2:
        {
            float x;
            printf("Enter the value of the angle inside the Sin: ");
            scanf("%f", &x);
            res = sinn(x);
            printf("\n%f\n", res);
            break;
        }
        case 3:
        {
            float x;
            printf("Enter the value of the angle inside the cos: ");
            scanf("%f", &x);
            res = coss(x);
            printf("\n%f\n", res);
            break;
        }
        case 4:
        {
            float x;
            printf("Enter the value anu number to calculate e power the number ");
            scanf("%f", &x);
            res = epoww(x);
            printf("\n%f\n", res);
            break;
        }
        case 5:
        {
            float x;
            printf("Enter the value of the number inside the Ln ");
            scanf("%f", &x);
            res = lnn(x);
            printf("\n%f\n", res);
            break;
        }
        case 6:
        {
            float x;
            printf("Enter the value of the number inside the arctan ");
            scanf("%f", &x);
            res = tann(x);
            printf("\n%f\n", res);
            break;
        }
        case 0:
            printf("Good bye!");
            break;
        default:
            printf("Error\n");
        }
    } while (operation != 0);
    return 0;
}
