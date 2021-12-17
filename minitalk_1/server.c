/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschmidt <tschmidt@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 17:48:07 by tschmidt          #+#    #+#             */
/*   Updated: 2021/12/17 11:33:39 by tschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h> // for pid_t gitpid(void); & for write...
#include <stdlib.h> // for exit
#include "ft_printf/ft_printf.h"

void sighandler(int signum) {
   ft_printf("Caught signal %d, coming out...\n", signum);
   exit(1);
}

int main ()
{
	struct sigaction	new_action;

	ft_printf("\nThis is your server's PID: %d \nUse it to send messages via the client! :)\n\n", getpid());
//    while(1) {
//       ft_printf("Going to sleep for a second...\n");
//       sleep(1); 
//    }
   return(0);
}
