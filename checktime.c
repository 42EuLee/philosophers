if (s_to_m() > info->death_timer)
		{
			printf("%ld %d died\n", s_to_m(), info->id);
			info->ptr->dead = 1;
			break ;
		}