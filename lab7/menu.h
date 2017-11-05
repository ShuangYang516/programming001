/********************************************************************/
/* Copyright (C) SSE-USTC, 2017-2018                                */
/*                                                                  */
/*  FILE NAME             :  linktabe.c                             */
/*  PRINCIPAL AUTHOR      :  lifangfang                             */
/*  SUBSYSTEM NAME        :  LinkTable                              */
/*  MODULE NAME           :  LinkTable                              */
/*  LANGUAGE              :  C                                      */
/*  TARGET ENVIRONMENT    :  ANY                                    */
/*  DATE OF FIRST RELEASE :  2017/11/4                              */
/*  DESCRIPTION           :  interface of Link Table                */
/********************************************************************/

/*
 * Revision log:
 *
 * Created by lifangfang ,2017/11/4
 * Provide right Callback interface by sudanyuan,2017/10/19
 *
 */



/* add cmd to menu */
int MenuConfig(char * cmd, char * desc, void (*handler)(int argc, char *argv[]));

/* Menu Engine Execute */
int ExecuteMenu();
