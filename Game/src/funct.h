//-------------------------------------------------------------------------
/*
Copyright (C) 1996, 2003 - 3D Realms Entertainment

This file is part of Duke Nukem 3D version 1.5 - Atomic Edition

Duke Nukem 3D is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  

See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License
aint32_t with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

Original Source: 1996 - Todd Replogle
Prepared for public release: 03/21/2003 - Charlie Wiederhold, 3D Realms
*/
//-------------------------------------------------------------------------

#ifndef FUNCT_H
#define FUNCT_H

#include "duke3d.h"

extern void sendscore(char  *s);
extern void SoundStartup(void );
extern void SoundShutdown(void );
extern void MusicStartup(void );
extern void MusicShutdown(void );
extern int USRHOOKS_GetMem(void  **ptr,uint32_t size);
extern int USRHOOKS_FreeMem(void  *ptr);
extern void intomenusounds(void );
extern void playmusic(char  *fn);
extern uint8_t  loadsound(uint16_t num);
extern int xyzsound(short num,short i,int32_t x,int32_t y,int32_t z);
extern void sound(short num);
extern int spritesound(uint16_t num,short i);
extern void stopsound(short num);
extern void stopenvsound(short num,short i);
extern void pan3dsound(void );
extern void TestCallBack(int32_t num);
extern short callsound(short sn,short whatsprite);
extern short check_activator_motion(short lotag);
extern uint8_t  isadoorwall(short dapic);
extern uint8_t  isanunderoperator(short lotag);
extern uint8_t  isanearoperator(short lotag);
extern short checkcursectnums(short sect);
extern int32_t ldist(spritetype *s1,spritetype *s2);
extern int32_t dist(spritetype *s1,spritetype *s2);
extern short findplayer(spritetype *s,int32_t *d);
extern short findotherplayer(short p,int32_t *d);
extern void doanimations(void );
extern int32_t getanimationgoal(int32_t *animptr);
extern int32_t setanimation(short animsect,int32_t *animptr,int32_t thegoal,int32_t thevel);
extern void animatecamsprite(void );
extern void animatewalls(void );
extern uint8_t  activatewarpelevators(short s,short d);
extern void operatesectors(short sn,short ii);
extern void operaterespawns(short low);
extern void operateactivators(short low,short snum);
extern void operatemasterswitches(short low);
extern void operateforcefields(short s,short low);
extern uint8_t  checkhitswitch(short snum,int32_t w,uint8_t  switchtype);
extern void activatebysector(short sect,short j);
extern void checkhitwall(short spr,short dawallnum,int32_t x,int32_t y,int32_t z,short atwith);
extern void checkplayerhurt(struct player_struct *p,short j);
extern uint8_t  checkhitceiling(short sn);
extern void checkhitsprite(short i,short sn);
extern void allignwarpelevators(void );
extern void cheatkeys(short snum);
extern void checksectors(short snum);
extern void RTS_AddFile(char  *filename);
extern void RTS_Init(char *filename);
extern int32 RTS_NumSounds(void );
extern int32 RTS_SoundLength(int32 lump);
extern char  *RTS_GetSoundName(int32 i);
extern void RTS_ReadLump(int32 lump,void *dest);
extern void *RTS_GetSound(int32 lump);
extern void xyzmirror(short i,short wn);
extern void vscrn(void );
int countfragbars(void);
extern void pickrandomspot(short snum);
extern void resetplayerstats(short snum);
extern void resetweapons(short snum);
extern void resetinventory(short snum);
extern void resetprestat(short snum,uint8_t  g);
extern void setupbackdrop(short backpicnum);
extern void cachespritenum(short i);
extern void cachegoodsprites(void );
extern void prelevel(uint8_t  g);
extern void newgame(uint8_t  vn,uint8_t  ln,uint8_t  sk);
extern void resetpspritevars(uint8_t  g);
extern void resettimevars(void );
extern void genspriteremaps(void );
extern void waitforeverybody(void);
extern uint8_t  checksum(int32_t sum);
extern uint8_t  getsound(uint16_t num);
extern void precachenecessarysounds(void );
extern void cacheit(void );
extern void dofrontscreens(void );
extern void enterlevel(uint8_t  g);
extern void setpal(struct player_struct *p);
extern void incur_damage(struct player_struct *p);
extern void quickkill(struct player_struct *p);
extern void forceplayerangle(struct player_struct *p);
extern void tracers(int32_t x1,int32_t y1,int32_t z1,int32_t x2,int32_t y2,int32_t z2,int32_t n);
extern int32_t hits(short i);
extern int32_t hitasprite(short i,short *hitsp);
extern int32_t hitawall(struct player_struct *p,short *hitw);
extern short aim(spritetype *s,short aang, short auto_aim);
extern void shoot(short i,short atwith);
extern void displayloogie(short snum);
extern uint8_t  animatefist(short gs,short snum);
extern uint8_t  animateknee(short gs,short snum);
extern uint8_t  animateknuckles(short gs,short snum);
extern void displaymasks(short snum);
extern uint8_t  animatetip(short gs,short snum);
extern uint8_t  animateaccess(short gs,short snum);
extern void displayweapon(short snum);
extern void getinput(short snum);
extern uint8_t  doincrements(struct player_struct *p);
extern void checkweapons(struct player_struct *p);
extern void processinput(short snum);
extern void cmenu(short cm);
extern void savetemp(char  *fn,uint8_t* daptr,int32_t dasiz);
extern void getangplayers(short snum);
extern int loadpheader(uint8_t  spot,int32 *vn,int32 *ln,int32 *psk,int32 *numplr);
extern int loadplayer(int8_t spot);
extern int saveplayer(int8_t spot);
extern void sendgameinfo(void );
extern int probe(int x,int y,int i,int n);
extern int probeXduke(int x,int y,int i,int n, int32_t spriteSize);
extern int menutext(int x,int y,short s,short p,char  *t);
extern int menutextc(int x,int y,short s,short p,char  *t);
extern void bar(int x,int y,short *p,short dainc,uint8_t  damodify,short s,short pa);
extern void dispnames(void );
extern int getfilenames(char  kind[]);
extern void sortfilenames(void);
extern void menus(void );
void gameexitanycase(void);
extern void palto(uint8_t  r,uint8_t  g,uint8_t  b,int32_t e, int present);
extern void drawoverheadmap(int32_t cposx,int32_t cposy,int32_t czoom,short cang);
extern void playanm(char  *fn,uint8_t );
extern short getincangle(short a,short na);
extern uint8_t  ispecial(uint8_t  c);
extern uint8_t  isaltok(uint8_t  c);
extern void getglobalz(short i);
extern void makeitfall(short i);
extern void getlabel(void );
extern int32_t keyword(void );
extern int32_t transword(void );
extern void transnum(void );
extern uint8_t  parsecommand(int readfromGRP );
extern void passone(int readfromGRP);
extern void loadefs(char  *fn,char  *mptr, int readfromGRP);
extern uint8_t  dodge(spritetype *s);
extern short furthestangle(short i,short angs);
extern short furthestcanseepoint(short i,spritetype *ts,int32_t *dax,int32_t *day);
extern void alterang(short a);
extern void move(void);
extern void parseifelse(int32_t condition);
extern uint8_t  parse(void );
extern void execute(short i,short p,int32_t x);
extern void overwritesprite(int32_t thex,int32_t they,short tilenum,int8_t shade,uint8_t  stat,uint8_t  dapalnum);
extern void timerhandler(void);
extern int inittimer(int);
extern void uninittimer(void );
extern int gametext(int x,int y,char  *t,uint8_t  s,short dabits);
extern int gametextpart(int x,int y,char  *t,uint8_t  s,short p);
extern int minitext(int x,int y,char  *t,uint8_t  p,uint8_t  sb);
extern void gamenumber(int32_t x,int32_t y,int32_t n,uint8_t  s);
extern void ShutDown(void );
extern void allowtimetocorrecterrorswhenquitting(void );
extern void getpackets(void );
extern void faketimerhandler(void);
extern void checksync(void );
extern void check_fta_sounds(short i);
extern short inventory(spritetype *s);
extern short badguy(spritetype *s);
extern short badguypic(short pn);
extern void myos(int32_t x,int32_t y,short tilenum,int8_t shade,uint8_t  orientation);
extern void myospal(int32_t x,int32_t y,short tilenum,int8_t shade,uint8_t  orientation,uint8_t  p);
extern void invennum(int32_t x,int32_t y,uint8_t  num1,uint8_t  ha,uint8_t  sbits);
extern void weaponnum(short ind,int32_t x,int32_t y,int32_t num1,int32_t num2,uint8_t  ha);
extern void weaponnum999(uint8_t  ind,int32_t x,int32_t y,int32_t num1,int32_t num2,uint8_t  ha);
extern void weapon_amounts(struct player_struct *p,int32_t x,int32_t y,int32_t u);
extern void digitalnumber(int32_t x,int32_t y,int32_t n,uint8_t  s,uint8_t  cs);
extern void scratchmarks(int32_t x,int32_t y,int32_t n,uint8_t  s,uint8_t  p);
extern void displayinventory(struct player_struct *p);
extern void displayfragbar(void );
void drawsmallweapon(short weapon, float scale, short x, short y); // xduke
extern void coolgaugetext(short snum);
extern void tics(short offx, short offy , short color);
extern void clocks(void );
extern void coords(short snum);
extern void operatefta(void);
extern void FTA(short q,struct player_struct *p, int mode);
extern void showtwoscreens(void );

extern void gameexit(char  *t);
extern short strget(short x,short y,char  *t,short dalen,short c);
extern void displayrest(int32_t smoothratio);
extern void updatesectorz(int32_t x,int32_t y,int32_t z,short *sectnum);
extern void view(struct player_struct *pp,int32_t *vx,int32_t *vy,int32_t *vz,short *vsectnum,short ang,short horiz);
extern void drawbackground(void );
extern void displayrooms(short snum,int32_t smoothratio);
extern short LocateTheLocator(short n,short sn);
extern short EGS(short whatsect,int32_t s_x,int32_t s_y,int32_t s_z,short s_pn,int8_t s_s,int8_t s_xr,int8_t s_yr,short s_a,short s_ve,int32_t s_zv,short s_ow,int8_t s_ss);
extern uint8_t  wallswitchcheck(short i);
extern short spawn(short j,short pn);
extern void animatesprites(int32_t x,int32_t y,short a,int32_t smoothratio);
extern void cheats(void );
extern void nonsharedkeys(void );
extern void comlinehelp(char  **argv);
extern void checkcommandline(int argc,char  **argv);
extern void printstr(short x,short y,uint8_t  string[],uint8_t  attribute);
extern void Logo(void );
extern void loadtmb(void );
extern void compilecons(void );
extern int32_t encodescriptptr(int32_t* scptr);
extern int32_t* decodescriptptr(int32_t scptr);
extern void Startup(void );
extern void getnames(void );
extern int main(int argc,char  **argv);
extern uint8_t  opendemoread(uint8_t  which_demo);
extern void opendemowrite(void );
extern void record(void );
extern void closedemowrite(void );
extern int32_t playback(void );
extern uint8_t  moveloop(void);
extern void fakedomovethingscorrect(void);
extern void fakedomovethings(void );
extern uint8_t  domovethings(void );
extern void displaybonuspics(short x,short y,short p);
extern void doorders(void );
extern void dobonus(uint8_t  bonusonly);
extern void cameratext(short i);
extern void vglass(int32_t x,int32_t y,short a,short wn,short n);
extern void lotsofglass(short i,short wallnum,short n);
extern void spriteglass(short i,short n);
extern void ceilingglass(short i,short sectnum,short n);
extern void lotsofcolourglass(short i,short wallnum,short n);
extern void SetupGameButtons(void );
extern int32_t GetTime(void );
extern void CenterCenter(void );
extern void UpperLeft(void );
extern void LowerRight(void );
extern void CenterThrottle(void );
extern void CenterRudder(void );
extern void takescreenshot(void );
extern void CONFIG_GetSetupFilename(void );
extern int32 CONFIG_FunctionNameToNum(char  *func);
extern char  *CONFIG_FunctionNumToName(int32 func);
extern int32 CONFIG_AnalogNameToNum(char  *func);
extern void CONFIG_SetDefaults(void );
extern void CONFIG_ReadKeys(void );
extern void CONFIG_SetupMouse(int32 scripthandle);
extern void CONFIG_SetupGamePad(int32 scripthandle);
extern void CONFIG_SetupJoystick(int32 scripthandle);
extern void readsavenames(void );
extern void CONFIG_ReadSetup(void );
extern void CONFIG_WriteSetup(void );
extern void CheckAnimStarted(uint8_t  *funcname);
extern uint16 findpage(uint16 framenumber);
extern void loadpage(uint16 pagenumber,uint16 *pagepointer);
extern void CPlayRunSkipDump(byte *srcP,byte *dstP);
extern void renderframe(uint16 framenumber,uint16 *pagepointer);
extern void drawframe(uint16 framenumber);
extern void ANIM_LoadAnim(byte *buffer);
extern void ANIM_FreeAnim(void );
extern int32 ANIM_NumFrames(void );
extern byte *ANIM_DrawFrame(int32 framenumber);
extern byte *ANIM_GetPalette(void );
extern void updateinterpolations(void);
extern void setinterpolation(int32_t *posptr);
extern void stopinterpolation(int32_t *posptr);
extern void dointerpolations(int32_t smoothratio);
extern void restoreinterpolations(void);
extern int32_t ceilingspace(short sectnum);
extern int32_t floorspace(short sectnum);
extern void addammo(short weapon,struct player_struct *p,short amount);
extern void addweapon(struct player_struct *p,short weapon);
extern void checkavailinven(struct player_struct *p);
extern void checkavailweapon(struct player_struct *p);
extern int32_t ifsquished(short i,short p);
extern void hitradius(short i,int32_t r,int32_t hp1,int32_t hp2,int32_t hp3,int32_t hp4);
extern int movesprite(short spritenum,int32_t xchange,int32_t ychange,int32_t zchange,uint32_t cliptype);
extern short ssp(short i,uint32_t cliptype);
extern void insertspriteq(short i);
extern void lotsofmoney(spritetype *s,short n);
extern void guts(spritetype *s,short gtype,short n,short p);
extern void setsectinterpolate(short i);
extern void clearsectinterpolate(short i);
extern void ms(short i);
extern void movefta(void );
extern short ifhitsectors(short sectnum);
extern short ifhitbyweapon(short sn);
extern void movecyclers(void );
extern void movedummyplayers(void );
extern void moveplayers(void );
extern void movefx(void );
extern void movefallers(void );
extern void movestandables(void );
extern void bounce(short i);
extern void moveweapons(void );
extern void movetransports(void );
extern void moveeffectors(void );
extern void moveactors(void );
extern void moveexplosions(void );

#endif
