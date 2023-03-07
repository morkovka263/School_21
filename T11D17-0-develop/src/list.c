#include "list.h"

#include "door_struct.h"
struct node* init(struct door* door) {
    struct node* new_node = NULL;
    if (door != NULL) {
        new_node = malloc(sizeof(struct node));
        new_node->n = door;
        new_node->next = NULL;
    }
}
struct node* add_door(struct node* elem, struct door* door) {
    struct node* new_node = NULL;
    if (door != NULL && elem != NULL) {
        new_node = init(door);
        new_node->next = elem->next;
        elem->next = new_node;
    }
}
struct node* find_door(int door_id, struct node* root) {
    struct node* search = root;
    if (root != NULL) {
        while (search != NULL && search->n->id != door_id) {
            search = search->next;
        }
    }
    return search;
}
struct node* remove_door(struct node* elem, struct node* root) {
    if (root != NULL && elem != NULL) {
        struct node* prev = root;
        struct node* ne = root;
        while (ne ! = elem && n != NULL) {
            prev = ne;
            ne = ne->next;
        }
        if (ne != NULL) {
            if (ne != root) {
                prev->next = ne->next;
                free(ne);
            } else {
                if (root->next != NULL) {
                    root = root->next;
                } else {
                    root = NULL;
                }
                free(ne);
            }
        }
        return root;
    }
}
void destroy(struct node* root) {
    if (root != NULL) {
        struct node* destroyer = root;
        while (destroyer != NULL) {
            root = root->next;
            free(destroyer);
            destroyer = root;
        }
    }
}