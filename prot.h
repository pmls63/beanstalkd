/* prot.h - protocol implementation header */

#ifndef prot_h
#define prot_h

#include "job.h"
#include "conn.h"

/* space for 16 Mi jobs */
#define HEAP_SIZE 16 * 1024 * 1024

/* measured in seconds */
#define RESERVATION_TIMEOUT 120

#define MSG_RESERVED "RESERVED"

void prot_init();

void reply(conn c, char *line, int len, int state);
void reply_job(conn c, job j, const char *word);

void enqueue_waiting_conn(conn c);

int enqueue_job(job j);
void process_queue();

job peek_job(unsigned long long int id);

unsigned int count_ready_jobs();

#endif /*prot_h*/
