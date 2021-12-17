/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschmidt <tschmidt@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 17:48:00 by tschmidt          #+#    #+#             */
/*   Updated: 2021/12/17 12:40:12 by tschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> // for exit
#include <signal.h> // for sigaction
#include <unistd.h> // for pause

void	handler(int num)
{
	write(1, "Stuff goes here", 15); // I guess I should use this function to send the message?
}

int	main(int argc, char **argv)
{
	struct sigaction	message;
	
	message.sa_handler = handler;
	
	if(argc != 3)
		return(1);
		//exit(1); // terminates a process - so should I use this instead of return()?
	
	sigaction(SIGUSR1, &message, NULL);
	sigaction(SIGUSR2, &message, NULL); // why do I have 2 signals?

	while (1)
	{
		//do stuff - or not?
		//sleep(1); //sleep 1 sec; instead: pause 
		pause(); // causes the calling process (or thread) to sleep until a signal is delivered that either terminates the process or causes the invocation of a signal-catching function.
	}
	return(0);
}