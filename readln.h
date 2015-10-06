#pragma once
#ifndef READLN_H
#define READLN_H

#ifdef __cplusplus
extern "C" {
#endif

	char* readln(); 
	void freeln(char *); 
	/* returns 1 if line contains any matches of pattern, 0 otherwise */

#ifdef __cplusplus
}
#endif
#endif /* ! RETURN_H */