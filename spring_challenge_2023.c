#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

// STRUCTURS DEF
#define NUMBER_OF_CELLS 100 

typedef struct {
    int neigh_0[NUMBER_OF_CELLS];
    int neigh_1[NUMBER_OF_CELLS];
    int neigh_2[NUMBER_OF_CELLS];
    int neigh_3[NUMBER_OF_CELLS];
    int neigh_4[NUMBER_OF_CELLS];
    int neigh_5[NUMBER_OF_CELLS];
} t_list_neigh;

// UTIL FUNTIONS 

int cell_runner(int *type_index, int num_of_type_cells, int *resources)
{
    if (resources[type_index[num_of_type_cells]] <= 0) 
    {
        return (1);
    }
    return (0); 
}

void set_line(int origin, int destiny, int strong){
    printf("LINE %i %i %i", origin, destiny, strong);
    printf(";");
 }

void set_beacon(int destiny, int strong){
    printf("BEACON %i %i", destiny, strong);
    printf(";");
 }

int counter_resources_of(int *initial_resources, int **resource_index, int total_resource)
{
    int total = 0;
    for(int i = 0; i < total_resource; i++)
    {
        total = total + initial_resources[resource_index[0][i]];
    }
    return (total);
}

void is_resource_next(int type, int neigh_index, int my_base_index)
{
    if(type == 1)
    {
        set_beacon(neigh_index, 6);
    }
/*     if(type == 2)
    {
        set_beacon(neigh_index, 6);
    } */
}

void neigh_resources_catcher(int *type, int *resources, int my_base_index,  t_list_neigh neighbors)
{
    if (type[neighbors.neigh_0[my_base_index]] > 0 && resources[neighbors.neigh_0[my_base_index]] > 0)
    {
        is_resource_next(type[neighbors.neigh_0[my_base_index]], neighbors.neigh_0[my_base_index], my_base_index);        
    }
    if (type[neighbors.neigh_1[my_base_index]] > 0 && resources[neighbors.neigh_1[my_base_index]] > 0)
    {
        is_resource_next(type[neighbors.neigh_1[my_base_index]], neighbors.neigh_1[my_base_index], my_base_index);        
    }
    if (type[neighbors.neigh_2[my_base_index]] > 0 && resources[neighbors.neigh_2[my_base_index]] > 0)
    {
        is_resource_next(type[neighbors.neigh_2[my_base_index]], neighbors.neigh_2[my_base_index], my_base_index);        
    }
    if (type[neighbors.neigh_3[my_base_index]] > 0 && resources[neighbors.neigh_3[my_base_index]] > 0)
    {
        is_resource_next(type[neighbors.neigh_3[my_base_index]], neighbors.neigh_3[my_base_index], my_base_index);        
    }
    if (type[neighbors.neigh_4[my_base_index]] > 0 && resources[neighbors.neigh_4[my_base_index]] > 0)
    {
        is_resource_next(type[neighbors.neigh_4[my_base_index]], neighbors.neigh_4[my_base_index], my_base_index);        
    }
    if (type[neighbors.neigh_5[my_base_index]] > 0 && resources[neighbors.neigh_5[my_base_index]] > 0)
    {
        is_resource_next(type[neighbors.neigh_5[my_base_index]], neighbors.neigh_5[my_base_index], my_base_index);        
    }
}


void is_resource_next_to_base(int type, int neigh_index, int my_base_index)
{
    if(type == 1)
    {
        set_beacon(neigh_index, 6);
    }
    if(type == 2)
    {
        set_beacon(neigh_index, 6);
    }
}

void neigh_resources_catcher_base(int *type, int *resources, int my_base_index,  t_list_neigh neighbors)
{
    if (type[neighbors.neigh_0[my_base_index]] > 0 && resources[neighbors.neigh_0[my_base_index]] > 0)
    {
        is_resource_next_to_base(type[neighbors.neigh_0[my_base_index]], neighbors.neigh_0[my_base_index], my_base_index);        
    }
    if (type[neighbors.neigh_1[my_base_index]] > 0 && resources[neighbors.neigh_1[my_base_index]] > 0)
    {
        is_resource_next_to_base(type[neighbors.neigh_1[my_base_index]], neighbors.neigh_1[my_base_index], my_base_index);        
    }
    if (type[neighbors.neigh_2[my_base_index]] > 0 && resources[neighbors.neigh_2[my_base_index]] > 0)
    {
        is_resource_next_to_base(type[neighbors.neigh_2[my_base_index]], neighbors.neigh_2[my_base_index], my_base_index);        
    }
    if (type[neighbors.neigh_3[my_base_index]] > 0 && resources[neighbors.neigh_3[my_base_index]] > 0)
    {
        is_resource_next_to_base(type[neighbors.neigh_3[my_base_index]], neighbors.neigh_3[my_base_index], my_base_index);        
    }
    if (type[neighbors.neigh_4[my_base_index]] > 0 && resources[neighbors.neigh_4[my_base_index]] > 0)
    {
        is_resource_next_to_base(type[neighbors.neigh_4[my_base_index]], neighbors.neigh_4[my_base_index], my_base_index);        
    }
    if (type[neighbors.neigh_5[my_base_index]] > 0 && resources[neighbors.neigh_5[my_base_index]] > 0)
    {
        is_resource_next_to_base(type[neighbors.neigh_5[my_base_index]], neighbors.neigh_5[my_base_index], my_base_index);        
    }
}

int resources_next_base_neigh(int type,int resource)
{
    if((type == 1 || type == 2) && resource > 0)
        return (1);
    return (0);
}

void invert_inner_array(int **array, int size)
{
    for (int i = 0; i < size; i++) {
        int start = 0;
        int end = size - 1;
        
        while (start < end) {
            int temp = array[i][start];
            array[i][start] = array[i][end];
            array[i][end] = temp;
            
            start++;
            end--;
        }
    }
}


/* AYUDA CON LA DISPOSICION DE LOS RECURSOS Y SU CERCANÍA */

typedef struct {
    int index;
    double distance;
} CellDistance;

int compare(const void *a, const void *b) {
    const CellDistance *cellA = (const CellDistance *)a;
    const CellDistance *cellB = (const CellDistance *)b;
    if (cellA->distance < cellB->distance)
        return -1;
    else if (cellA->distance > cellB->distance)
        return 1;
    else
        return 0;
}

void get_resources_by_proximity(int *type, int *resources, int **crystals_index, int **eggs_index, int *my_base_index, int total_crystals, int total_eggs, int number_of_cells, int number_of_bases) 
{
    CellDistance crystals_dist[total_crystals*2];
    CellDistance eggs_dist[total_eggs*2];

    int crystal_count = 0;
    int egg_count = 0;

    // Calculate the distance of each cell with resources to the base
    for (int j = 0; j < number_of_bases; j++)
    {
        for (int i = 0; i < number_of_cells; i++) {
            if (type[i] == 2 && resources[i] > 0) {
                double dx = abs((my_base_index[j] % 10) - (i % 10));
                double dy = abs((my_base_index[j] / 10) - (i / 10));
                double distance = sqrt(dx * dx + dy * dy);
                crystals_dist[crystal_count].index = i;
                crystals_dist[crystal_count].distance = distance;
                crystal_count++;
            } else if (type[i] == 1 && resources[i] > 0) {
                double dx = abs((my_base_index[j] % 10) - (i % 10));
                double dy = abs((my_base_index[j] / 10) - (i / 10));
                double distance = sqrt(dx * dx + dy * dy);
                eggs_dist[egg_count].index = i;
                eggs_dist[egg_count].distance = distance;
                egg_count++;
            }
        }
    }

    // Sort the resources by proximity
    qsort(crystals_dist, crystal_count, sizeof(CellDistance), compare);
    qsort(eggs_dist, egg_count, sizeof(CellDistance), compare);

    // Save the sorted indices in the output arrays
    for (int i = 0; i < number_of_bases; i++)
    {
        for (int j = 0; j < total_crystals; j++) {
            crystals_index[i][j] = crystals_dist[j].index;
            //crystals_index[i][j][1] = i;  // Optional: Store the sorted index for each crystal
        }
        for (int j = 0; j < total_eggs; j++) {
            eggs_index[i][j] = eggs_dist[j].index;
            //eggs_index[i][j][1] = i;  // Optional: Store the sorted index for each egg
        }
    }
}


int main()
{
    // amount of hexagonal cells in this map
    int number_of_cells;
    scanf("%d", &number_of_cells);
    // 0 for empty, 1 for eggs, 2 for crystal
    int type[number_of_cells];

    // the initial amount of eggs/crystals on this cell
    int initial_resources[number_of_cells];

    // the index of the neighbouring cell for each direction
    t_list_neigh neighbors;
    for (int i = 0; i < number_of_cells; i++) {
        scanf("%d%d%d%d%d%d%d%d", &type[i], &initial_resources[i], &neighbors.neigh_0[i], &neighbors.neigh_1[i], &neighbors.neigh_2[i], &neighbors.neigh_3[i], &neighbors.neigh_4[i], &neighbors.neigh_5[i]);
    }
 
    // COUNTING RESOURCES
    int total_cristals = 0;
    int total_eggs = 0;
    for(int i = 0; i <= number_of_cells; i++)
    {
        if(type[i] == 1)
        {
            total_eggs++;
        }
        if(type[i] == 2)
        {
            total_cristals++;
        }
    }

    // BASES
    int number_of_bases;
    scanf("%d", &number_of_bases);
    int my_base_index[number_of_bases];
    for (int i = 0; i < number_of_bases; i++) {
        scanf("%d", &my_base_index[i]);
    }

    int opp_base_index;
    for (int i = 0; i < number_of_bases; i++) {
        scanf("%d", &opp_base_index);
    }

    // ASIGNANDO A ARRAYS EL INDEX DE CRISTAL Y EGGS
    int **cristals_index;
    cristals_index = (int **)malloc(sizeof(int *) * number_of_bases);
    for (int i = 0; i < total_cristals; i++) {
        cristals_index[i] = (int *)malloc(sizeof(int *) * (total_cristals + 1));
    }

    int **eggs_index;
    eggs_index = (int **)malloc(sizeof(int *) * number_of_bases);
    for (int i = 0; i < total_eggs; i++) {
        eggs_index[i] = (int *)malloc(sizeof(int *) * (total_eggs + 1));
    }

    get_resources_by_proximity(type, initial_resources, cristals_index, eggs_index, my_base_index, total_cristals, total_eggs, number_of_cells, number_of_bases);

/*     invert_inner_array( cristals_index,  total_cristals);
    invert_inner_array( eggs_index,  total_eggs);
 */
    // CONTADOR TOTAL DE RECURSOS
    int total_egg_resources = counter_resources_of(initial_resources, eggs_index, total_eggs);
    int total_cristal_resources = counter_resources_of(initial_resources, cristals_index, total_cristals);

    // game loop
    while (1) 
    {
        // the current amount of eggs/crystals on this cell
        int resources[number_of_cells];
        // the amount of your ants on this cell
        int my_ants[number_of_cells];
        // the amount of opponent ants on this cell
        int opp_ants[number_of_cells];
        for (int i = 0; i < number_of_cells; i++) 
            scanf("%d%d%d", &resources[i], &my_ants[i], &opp_ants[i]);
        
        
        //ACTUALIZACIÖN DE RESOURCES TOTALES
        int eggs_now = 0;
        int cristals_now = 0;
        int opp_ants_now = 0;
        int my_ants_now = 0;
        for(int i = 0; i <= number_of_cells; i++)
        {
            if(type[i] == 1)
            {
                eggs_now = eggs_now + resources[i];
            }
            if(type[i] == 2)
            {
                cristals_now = cristals_now + resources[i];
            }
            if(opp_ants[i])
            {
                opp_ants_now = opp_ants_now + opp_ants[i];
            }
            if(my_ants[i])
            {
                my_ants_now = my_ants_now + my_ants[i];
            }
        }

        fprintf(stderr, "my ants: %i\n opp ants: %i\ncristal_now: %i\n total_cristal_resources: %i\n", my_ants_now, opp_ants_now, cristals_now, total_cristal_resources);
        for(int i = 0; i < number_of_bases; i++)
        {
            neigh_resources_catcher_base(type, resources, my_base_index[i], neighbors);
            for(int j = 0; j <= (total_cristals/2 + 1); j++)
            {
                if(number_of_bases > 1)
                {
                    for( int k = 0; k < total_cristals; k++)
                    {
                        if(cristals_index[0][j] != cristals_index[1][k])
                        {
                            neigh_resources_catcher(type, resources, cristals_index[i][j], neighbors);
                            if(resources[cristals_index[i][k]] > 0 && opp_ants[cristals_index[i][k]] == 0)
                            {
                                set_line(my_base_index[i], cristals_index[i][k],5);
                            }
                            if(opp_ants[cristals_index[i][k]] > 0 && opp_ants[cristals_index[i][k]] < my_ants[cristals_index[i][k]])
                            {
                                set_line(my_base_index[i], cristals_index[i][k],5);
                            }
                            if ((my_ants_now > opp_ants_now 
                                && opp_ants[cristals_index[i][k]] > my_ants[cristals_index[i][k]]) && opp_ants[cristals_index[i][k]] > 0)
                            {
                                if(resources[cristals_index[i][k]] > 0)
                                    set_line(my_base_index[i], cristals_index[i][k],5);
                            }
                        }
                    }
                }
                else
                {
                    neigh_resources_catcher(type, resources, cristals_index[i][j], neighbors);
                    if(resources[cristals_index[i][j]] > 0 && opp_ants[cristals_index[i][j]] == 0)
                    {
                        set_line(my_base_index[i], cristals_index[i][j],5);
                    }
                    if(opp_ants[cristals_index[i][j]] > 0 && opp_ants[cristals_index[i][j]] < my_ants[cristals_index[i][j]])
                    {
                        set_line(my_base_index[i], cristals_index[i][j],5);
                    }
                    if ((my_ants_now > opp_ants_now 
                        && opp_ants[cristals_index[i][j]] > my_ants[cristals_index[i][j]]) && opp_ants[cristals_index[i][j]] > 0)
                    {
                        if(resources[cristals_index[i][j]] > 0)
                            set_line(my_base_index[i], cristals_index[i][j],5);
                    }

                }
            }
            if(resources[cristals_index[i][total_cristals/2 + 1]] == 0)
            {
                for(int j = total_cristals/2 + 1; j < total_cristals; j++)
                {
                    neigh_resources_catcher(type, resources, cristals_index[i][j], neighbors);
                    if(resources[cristals_index[i][j]] > 0 && opp_ants[cristals_index[i][j]] == 0)
                    {
                        set_line(my_base_index[i], cristals_index[i][j],5);
                    }
                    if(opp_ants[cristals_index[i][j]] > 0 && opp_ants[cristals_index[i][j]] < my_ants[cristals_index[i][j]])
                    {
                        set_line(my_base_index[i], cristals_index[i][j],5);
                    }
                }
            }

            for(int j = 0; j <= (total_eggs/2 + 1); j++)
            {
                neigh_resources_catcher_base(type, resources, eggs_index[i][j], neighbors);
                if(resources[eggs_index[i][j]] > 0 && opp_ants[eggs_index[i][j]] == 0)
                {
                    set_line(my_base_index[i], eggs_index[i][j],5);
                }
                if(opp_ants[eggs_index[i][j]] > 0 && opp_ants[eggs_index[i][j]] < my_ants[eggs_index[i][j]])
                {
                    set_line(my_base_index[i], eggs_index[i][j],5);
                }
            }
            if(resources[eggs_index[i][total_eggs/2 + 1]] == 0)
            {
                for(int j = total_cristals/2 + 1; j < total_cristals; j++)
                {
                    neigh_resources_catcher_base(type, resources, eggs_index[i][j], neighbors);
                    if(resources[eggs_index[i][j]] > 0 && opp_ants[eggs_index[i][j]] == 0)
                    {
                        set_line(my_base_index[i], eggs_index[i][j],5);
                    }
                    if(opp_ants[eggs_index[i][j]] > 0 && opp_ants[eggs_index[i][j]] < my_ants[eggs_index[i][j]])
                    {
                        set_line(my_base_index[i], eggs_index[i][j],5);
                    }
                }
            }
        }


        // WAIT | LINE <sourceIdx> <targetIdx> <strength> | BEACON <cellIdx> <strength> | MESSAGE <text>
        printf("\n");
    }

    return 0;
}