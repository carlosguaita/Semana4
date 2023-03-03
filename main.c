#include <stdio.h>

int menuPrincipal();
char menuFacturacion();
int imprimirFactura(float numa, float numb, float numc, float numd, float nume);
void ingresarCliente();
float leerCantidadProducto(char producto[]);
float calculoTotalProducto(float cantidad, float numPorMayor, float precioNormal, float precioPorMayor);
void imprimirProductos(char nomProdcuto[], float num, float numxM, float prc, float prcxM, float tot);

int main(int argc, char *argv[])
{
    // Definición variables
    int opcion1 = 0, continuar1 = 0;
    float numa = 0, numb = 0, numc = 0, numd = 0, nume = 0;

    // Inicio
    printf("*********BIENVENIDO AL SISTEMA DE FACTURACIÓN***********\n");
    // Menu Principal
    do
    {
        opcion1 = menuPrincipal();
        switch (opcion1)
        {
        case 1:
            // Opción a
            do
            {
                switch (menuFacturacion())
                {
                case 'a' /* constant-expression */:
                    numa = leerCantidadProducto("Llantas");
                    break;
                case 'b' /* constant-expression */:
                    numb = leerCantidadProducto("Kit Pastillas de freno");
                    break;
                case 'c' /* constant-expression */:
                    numc = leerCantidadProducto("Kit de embrague");
                    break;
                case 'd' /* constant-expression */:
                    numd = leerCantidadProducto("Faros");
                    break;
                case 'e' /* constant-expression */:
                    nume = leerCantidadProducto("Radiador");
                    break;
                default:
                    printf("la opción elegida no existe \n");
                    break;
                }
                printf("Desea facturar otro producto  1) Si   2) No: ");
                scanf("%d", &continuar1);
            } while (continuar1 == 1);
            break;
        case 2:
            opcion1 = imprimirFactura(numa, numb, numc, numd, nume);
            break;
        case 3:
            printf("Adios");
            opcion1 = 3;
            break;

        default:
            printf("Elija una opción correcta");
            break;
        }
    } while (opcion1 != 3);
    //

    return 0;
}

int menuPrincipal()
{
    int opcion1;
    printf("1) Facturar Producto\n");
    printf("2) Imprimir Factura\n");
    printf("3) Salir\n");
    printf("Seleccione una opción: ");
    scanf("%d", &opcion1);
    return opcion1;
}

char menuFacturacion()
{
    char opcion2;
    printf("Escoja los productos que desea facturar:\n");
    printf("a) Llantas (Precio: $150) (Precio al por mayor, desde 6 unidades: $130)\n");
    printf("b) Kit Pastillas de freno (Precio: $55) (Precio al por mayor, desde12 unidades: $45)\n");
    printf("c) Kit de embrague (Precio: $180) (Precio al por mayor, desde 8 unidades: $165)\n");
    printf("d) Faros (Precio: $70) (Precio al por mayor, desde 10 unidades: $60)\n");
    printf("e) Radiador (Precio: $120)(Precio al por mayor, desde 6 unidades: $105)\n");
    fflush(stdin);
    scanf("%c", &opcion2);
    return opcion2;
}

float leerCantidadProducto(char producto[])
{
    float cantProducto = 0;
    printf("Ingrese la cantidad de %s que desea facturar: ", producto);
    scanf("%f", &cantProducto);
    return cantProducto;
}

int imprimirFactura(float numa, float numb, float numc, float numd, float nume)
{
    float prca = 150, prcb = 55, prcc = 180, prcd = 70, prce = 120;
    float prcaxM = 130, prcbxM = 45, prccxM = 165, prcdxM = 60, prcexM = 105;
    float numaxM = 6, numbxM = 12, numcxM = 8, numdxM = 10, numexM = 6;
    float tota = 0, totb = 0, totc = 0, totd = 0, tote = 0;
    float subtotal = 0, total = 0;

    tota = calculoTotalProducto(numa, numaxM, prca, prcaxM);
    totb = calculoTotalProducto(numb, numbxM, prcb, prcbxM);
    totc = calculoTotalProducto(numc, numcxM, prcc, prccxM);
    totd = calculoTotalProducto(numd, numdxM, prcd, prcdxM);
    tote = calculoTotalProducto(nume, numexM, prce, prcexM);

    printf("*********   FACTURA ************\n");
    ingresarCliente();       
    printf("Producto               Número              valor           total\n");
    imprimirProductos("Llantas               ", numa, numaxM, prca, prcaxM, tota);
    imprimirProductos("Kit Pastillas de freno", numb, numbxM, prcb, prcbxM, totb);
    imprimirProductos("Kit de embrague       ", numc, numcxM, prcc, prccxM, totc);
    imprimirProductos("Faros                 ", numd, numdxM, prcd, prcdxM, totd);
    imprimirProductos("Radiador              ", nume, numexM, prce, prcexM, tote);

    subtotal = tota + totb + totc + totd + tote;
    printf("El subtotal sin descuento es: %.2f\n", subtotal);
    if (subtotal > 100 && subtotal <= 500)
    {
        printf("Se aplica un descuento del 5 porciento\n");
        subtotal = subtotal * 0.95;
    }
    else if (subtotal > 500 && subtotal <= 1000)
    {
        printf("Se aplica un descuento del 7 porciento\n");
        subtotal = subtotal * 0.93;
    }
    else if (subtotal > 1000)
    {
        printf("Se aplica un descuento del 10 porciento\n");
        subtotal = subtotal * 0.90;
    }
    else
    {
        printf("No se aplica descuento dado que el mónto no alcanzo el mínimo necesario\n");
    }

    total = subtotal * 1.12;

    printf("El subtotal es: %.2f\n", subtotal);
    printf("El total es: %.2f\n", total);
    return 3;
}

void imprimirProductos(char nomProdcuto[], float num, float numxM, float prc, float prcxM, float tot)
{
    if (num != 0)
    {
        if (num < numxM)
        {
            printf("%s %.2f                %.2f             %.2f\n", nomProdcuto, num, prc, tot);
        }
        else
        {
            printf("%s %.2f                %.2f             %.2f\n", nomProdcuto, num, prcxM, tot);
        }
    }
}

float calculoTotalProducto(float cantidad, float numPorMayor, float precioNormal, float precioPorMayor)
{
    float totalProducto = 0;
    if (cantidad < numPorMayor)
    {
        totalProducto = cantidad * precioNormal;
    }
    else
    {
        totalProducto = cantidad * precioPorMayor;
    }
    return totalProducto;
}

void ingresarCliente()
{
    char nombre[50];
    char cedula[50];
    printf("Ingrese su nombre: ");
    scanf("%s", &nombre);
    printf("Ingrese su número de cédula: ");
    fflush(stdin);
    scanf("%s", &cedula);
    printf("Nombre: %s\n", nombre);
    printf("Nro. cédula: %s\n", cedula);
}
