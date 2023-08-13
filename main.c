/*
--------------------------------------------------
    James William Fletcher (github.com/mrbid)
        July 2023
--------------------------------------------------
    C & SDL / OpenGL ES2 / GLSL ES
    Colour Converter: https://www.easyrgb.com

    VoxelPainter
    https://github.com/mrbid/voxelpaint
*/

#pragma GCC diagnostic ignored "-Wtrigraphs"

const unsigned char icon[] = { // 16, 16, 4
  "\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377"
  "\377\377\001\377\377\377\032\346\346\346k\346\346\346y\377\377\377%\377\377"
  "\377\001\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377"
  "\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\002"
  "\377\377\377%\336\336\336\215fff\356RRR\367\326\326\326\237\377\377\377,"
  "\377\377\377\002\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377"
  "\377\377\000\377\377\377\000\377\377\377\000\377\377\377\003\377\377\377-\326\326"
  "\326\240RRR\367\000JJ\377\000RR\377JJJ\371\314\314\314\247\377\377\377.\377\377"
  "\377\003\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377"
  "\000\377\377\377\004\377\377\377\070\314\314\314\255BBB\372\000JJ\377\000\214\214"
  "\377\000\231\231\377\000RR\377<AA\372\314\314\314\255\377\377\377\066\377\377"
  "\377\004\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\005\377\377\377"
  "A\275\275\275\273:::\374\000\063\063\377\000\231\231\377\000\314\314\377\000\326\326"
  "\377\000\231\231\377\000BB\377:::\374\275\275\275\267\377\377\377=\377\377\377"
  "\004\377\377\377\000\377\377\377\000\377\377\377#\275\275\275\267\040..\376\000\031"
  "\031\377\000JJ\377\000\326\326\377\000\367\367\377\000\367\367\377\000\336\336\377\000"
  "ff\377\000\031\031\377(\061\061\375\275\275\275\263\377\377\377%\377\377\377\000"
  "\377\377\377\001\377\377\377M{{{\353\000!!\377\000))\377\000\265\265\377\000\367\367"
  "\377\000\377\377\377\000\377\377\377\000\377\377\377\000\275\275\377\000\063\063\377"
  "\000!!\377sss\354\377\377\377Q\377\377\377\002\377\377\377\007\357\357\357v<AA"
  "\372\000JJ\377\000\255\255\377\000\357\357\377\000\377\377\377\000\377\377\377\000\377"
  "\377\377\000\377\377\377\000\367\367\377\000\255\255\377\000JJ\377:::\373\346\346"
  "\346{\377\377\377\007\377\377\377\020\326\326\326\234\026\060\060\377\000\204\204"
  "\377\000\326\326\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377"
  "\000\377\377\377\000\377\377\377\000\326\326\377\000\214\214\377\017++\377\326\326"
  "\326\236\377\377\377\021\377\377\377%\255\255\255\306\000JJ\377\000\245\245\377"
  "\000\336\336\377\000\357\357\377\000\377\377\377\000\377\377\377\000\377\377\377\000"
  "\377\377\377\000\357\357\377\000\336\336\377\000\255\255\377\000JJ\377\255\255\255"
  "\311\377\377\377'\377\377\377A\204\204\204\345\000ss\377\000\245\245\377\000\275"
  "\275\377\000\314\314\377\000\346\346\377\000\265\265\377\000\245\245\377\000\346\346"
  "\377\000\326\326\377\000\275\275\377\000\245\245\377\000ss\377\204\204\204\346\377"
  "\377\377D\377\377\377D{{{\345\000ZZ\377\000ff\377\000\214\214\377\000\245\245\377"
  "\000\214\214\377\000JJ\377\000JJ\377\000\214\214\377\000\245\245\377\000\214\214\377"
  "\000ff\377\000ZZ\377sss\353\377\377\377J\377\377\377\026\357\357\357p\245\245"
  "\245\317JJJ\372\000JJ\377\000RR\377\000ff\377\000ZZ\377\000ZZ\377\000ff\377\000RR\377\000"
  "JJ\377<AA\374\231\231\231\330\346\346\346\203\377\377\377\035\377\377\377"
  "\000\377\377\377\012\377\377\377\067\346\346\346\210\231\231\231\331\063\063\063"
  "\374\000!!\377\000!!\377\000!!\377\000!!\377\063\063\063\375\231\231\231\335\336\336"
  "\336\223\377\377\377A\377\377\377\020\377\377\377\001\377\377\377\000\377\377"
  "\377\000\377\377\377\001\377\377\377\017\377\377\377A\336\336\336\227\214\214"
  "\214\343\040((\376\040..\375\214\214\214\342\336\336\336\231\377\377\377E\377"
  "\377\377\022\377\377\377\001\377\377\377\000\377\377\377\000\377\377\377\000\377\377"
  "\377\000\377\377\377\000\377\377\377\000\377\377\377\002\377\377\377\024\377\377\377"
  "O\314\314\314\232\326\326\326\230\377\377\377M\377\377\377\025\377\377\377"
  "\002\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000"
};

//#define SKYBLUE
//#define NO_COMPRESSION
//#define VERBOSE

#include <time.h>
#ifndef NO_COMPRESSION
    #include <zlib.h>
#endif

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengles2.h>

#ifdef __linux__
    #include <unistd.h>
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <sys/time.h>
    #include <locale.h>
#endif

#include "inc/esVoxel.h"

#define uint GLuint
#define sint GLint
#define uchar unsigned char
#define forceinline __attribute__((always_inline)) inline

//*************************************
// globals
//*************************************
const char appTitle[] = "Voxel Paint Pro";
const char appVersion[] = "v1.1";
char *basedir, *appdir;
SDL_Window* wnd;
SDL_GLContext glc;
SDL_Surface* s_icon = NULL;
int winw = 1024, winh = 768;
int winw2 = 512, winh2 = 384;
float ww, wh;
float aspect, t = 0.f;
uint g_fps = 0;
uint ks[10] = {0};      // keystate
uint focus_mouse = 0;   // mouse lock
float ddist = 4096.f;   // view distance
float ddist2 = 4096.f*4096.f;
vec ipp;                // inverse player position
vec look_dir;           // camera look direction
int lray = 0;           // pointed at node index
float ptt = 0.f;        // place timing trigger (for repeat place)
float dtt = 0.f;        // delete timing trigger (for repeat delete)
float rtt = 0.f;        // replace timing trigger (for repeat replace)
float rrsp = 0.3f;      // repeat replace speed
uint fks = 0;           // F-Key state (fast mode toggle)
uint ise = 0;           // is selecting
uint itf = 0;           // is transforming (rotating)
vec sp1d, sp1, sp2, sdif, sdifo, sp1o; // selecting vars
float bigc = 0.f;       // big cursor start time

//*************************************
// utility functions
//*************************************
void timestamp(char* ts){const time_t tt = time(0);strftime(ts, 16, "%H:%M:%S", localtime(&tt));}
forceinline float fTime(){return ((float)SDL_GetTicks())*0.001f;}
#ifdef __linux__
    uint64_t microtime()
    {
        struct timeval tv;
        struct timezone tz;
        memset(&tz, 0, sizeof(struct timezone));
        gettimeofday(&tv, &tz);
        return 1000000 * tv.tv_sec + tv.tv_usec;
    }
    uint dirExist(const char* dir)
    {
        struct stat st;
        return (stat(dir, &st) == 0 && S_ISDIR(st.st_mode));
    }
    uint fileExist(const char* file)
    {
        struct stat st;
        return (stat(file, &st) == 0);
    }
#endif

//*************************************
// game state functions
//*************************************

// game data (for fast save and load)
#define max_voxels 4194304 // 4.2 million
#define header_size 68
#define max_data_size 67108932 // (max_voxels*sizeof(vec)) + header_size
typedef struct
{
    vec pp;     // player position
    vec pb;     // place block pos
    float sens; // mouse sensitivity
    float xrot; // camera x-axis rotation
    float yrot; // camera y-axis rotation
    float st;   // selected color
    float ms;   // player move speed
    float cms;  // custom move speed (high)
    float lms;  // custom move speed (low)
    uchar grav; // gravity on/off toggle
    uchar plock;// pitchlock on/off toggle
    uchar r1, r2;
    uint num_voxels;
    vec voxels[max_voxels]; // x,y,z,w (w = color_id)
}
game_state;
game_state g; // ~67mb

int swapfunc(const void *a, const void *b)
{
    const float aw = ((vec*)a)->w;
    const float bw = ((vec*)b)->w;
    if(aw == bw){return 0;}
    else if(aw == -1.f){return 1;}
    return 0;
}
void optimState()
{
    qsort(g.voxels, g.num_voxels, sizeof(vec), swapfunc);
    for(uint i = 0; i < g.num_voxels; i++)
    {
        if(g.voxels[i].w == -1.f)
        {
            g.num_voxels = i;
            break;
        }
    }
}

void defaultState(const uint type)
{
    g.sens = 0.003f;
    g.xrot = 0.f;
    g.yrot = 1.5f;
    g.pp = (vec){0.f, 4.f, 0.f};
    if(type == 0)
    {
        g.ms = 37.2f;
    }
    g.st = 18.f;
    g.pb = (vec){0.f, 0.f, 0.f, -1.f};
    if(type == 0)
    {
        g.lms = 37.2f;
        g.cms = 74.4f;
    }
    g.grav = 0;
    g.plock = 0;
    if(g.num_voxels == 0){g.num_voxels = 256;}
}

uint loadUncompressedState()
{
#ifdef __linux__
    setlocale(LC_NUMERIC, "");
    const uint64_t st = microtime();
#endif
    char file[256];
    sprintf(file, "%sworld.db", appdir);
    FILE* f = fopen(file, "rb");
    if(f != NULL)
    {
        fseek(f, 0, SEEK_END);
        long rs = ftell(f);
        fseek(f, 0, SEEK_SET);
        if(fread(&g, 1, rs, f) != rs)
        {
            char tmp[16];
            timestamp(tmp);
            printf("[%s] fread() was of an unexpected size.\n", tmp);
        }
        fclose(f);
        fks = (g.ms == g.cms); // update F-Key State
        char tmp[16];
        timestamp(tmp);
#ifndef __linux__
        printf("[%s] Loaded %u voxels.\n", tmp, g.num_voxels);
#else
        printf("[%s] Loaded %'u voxels. (%'lu μs)\n", tmp, g.num_voxels, microtime()-st);
#endif
        return 1;
    }
    return 0;
}

#ifdef NO_COMPRESSION
    void saveState(const char* fne)
    {
        optimState();
    #ifdef __linux__
        setlocale(LC_NUMERIC, "");
        const uint64_t st = microtime();
    #endif
        char file[256];
        sprintf(file, "%sworld.db%s", appdir, fne);
        FILE* f = fopen(file, "wb");
        if(f != NULL)
        {
            const size_t ws = header_size + (g.num_voxels*sizeof(vec));
            if(fwrite(&g, 1, ws, f) != ws)
            {
                char tmp[16];
                timestamp(tmp);
                printf("[%s] Save corrupted.\n", tmp);
            }
            fclose(f);
            char tmp[16];
            timestamp(tmp);
    #ifndef __linux__
            printf("[%s] Saved %u voxels.\n", tmp, g.num_voxels);
    #else
            printf("[%s] Saved %'u voxels. (%'lu μs)\n", tmp, g.num_voxels, microtime()-st);
    #endif
        }
    }

    uint loadState(){return loadUncompressedState();}
#else
    void saveState(const char* fne)
    {
        optimState();
    #ifdef __linux__
        setlocale(LC_NUMERIC, "");
        const uint64_t st = microtime();
    #endif
        char file[256];
        sprintf(file, "%sworld.gz%s", appdir, fne);
        gzFile f = gzopen(file, "wb1h");
        if(f != Z_NULL)
        {
            const size_t ws = header_size + (g.num_voxels*sizeof(vec));
            if(gzwrite(f, &g, ws) != ws)
            {
                char tmp[16];
                timestamp(tmp);
                printf("[%s] Save corrupted.\n", tmp);
            }
            gzclose(f);
            char tmp[16];
            timestamp(tmp);
    #ifndef __linux__
            printf("[%s] Saved %'u voxels.\n", tmp, g.num_voxels);
    #else
            printf("[%s] Saved %'u voxels. (%'lu μs)\n", tmp, g.num_voxels, microtime()-st);
    #endif
        }
    }

    uint loadState()
    {
    #ifdef __linux__
        setlocale(LC_NUMERIC, "");
        const uint64_t st = microtime();
    #endif
        char file[256];
        sprintf(file, "%sworld.gz", appdir);
        gzFile f = gzopen(file, "rb");
        if(f != Z_NULL)
        {
            int gr = gzread(f, &g, max_data_size);
            gzclose(f);
            fks = (g.ms == g.cms); // update F-Key State
            char tmp[16];
            timestamp(tmp);
    #ifndef __linux__
            printf("[%s] Loaded %u voxels\n", tmp, g.num_voxels);
    #else
            printf("[%s] Loaded %'u voxels. (%'lu μs)\n", tmp, g.num_voxels, microtime()-st);
    #endif
            return 1;
        }
        return 0;
    }
#endif

//*************************************
// ray & render functions
//*************************************

// render state id's
GLint projection_id;
GLint view_id;
GLint voxel_id;
GLint position_id;
GLint normal_id;
GLint texcoord_id;
GLint sampler_id;

// render state matrices
mat projection;
mat view;

// hit_vec will be untouched by this if there's no collision (function by hax/test_user)
#define RAY_DEPTH 70
int ray(vec *hit_vec, const uint depth, const vec vec_start_pos)
{
	int hit = -1;
	float bestdist;
	float start_pos[] = {vec_start_pos.x, vec_start_pos.y, vec_start_pos.z};
	float lookdir[] = {look_dir.x, look_dir.y, look_dir.z};
	for (int i = 0; i < g.num_voxels; i++)
    {
		if(g.voxels[i].w < 0.f){continue;}
		float offset[] = {g.voxels[i].x - start_pos[0], g.voxels[i].y - start_pos[1], g.voxels[i].z - start_pos[2]};
		int j = 0;
        // hmmmmmm... is there some decent way to get around this...
		float max = fabsf(offset[0]);
		float tmp = fabsf(offset[1]);
		if(tmp > max){max = tmp; j = 1;}
		tmp = fabsf(offset[2]);
		if(tmp > max){max = tmp; j = 2;}
		if (max <= 0.5f) { // unlikely but better than breaking... costs some cycles though
			*hit_vec = vec_start_pos;
			return i;
		}
		float dist_to_start = offset[j];
		if(dist_to_start > 0.f){dist_to_start -= 0.5f;}else{dist_to_start += 0.5f;}
		const float multiplier = dist_to_start / lookdir[j];
        // too far out (or not in the right direction), don't bother
		if(multiplier > depth || (hit != -1 && multiplier > bestdist) || multiplier < 0.f){continue;}
        // Might end up taking all 222 of those cycles below... :/
        // At least better than what it was originally though
        // And with enough out of range there's still a chance average comes out under
		{
			float pos[] = {start_pos[0] + (lookdir[0] * multiplier), start_pos[1] + (lookdir[1] * multiplier), start_pos[2] + (lookdir[2] * multiplier)};
			if (pos[0] > g.voxels[i].x + 1.5f || pos[0] < g.voxels[i].x - 1.5f ||
				pos[1] > g.voxels[i].y + 1.5f || pos[1] < g.voxels[i].y - 1.5f ||
				pos[2] > g.voxels[i].z + 1.5f || pos[2] < g.voxels[i].z - 1.5f) {continue;} // not even a chance of hitting
            ///
			if ((j == 0 || (pos[0] >= g.voxels[i].x - 0.5f && pos[0] <= g.voxels[i].x + 0.5f)) && // j == n so float inaccuracies won't proceed to tell me that it's out after I just put it on the edge
				(j == 1 || (pos[1] >= g.voxels[i].y - 0.5f && pos[1] <= g.voxels[i].y + 0.5f)) &&
				(j == 2 || (pos[2] >= g.voxels[i].z - 0.5f && pos[2] <= g.voxels[i].z + 0.5f))) { // hit
				hit = i;
				float sign;
				if(offset[j] > 0.f){sign = -1.f;}else{sign = 1.f;}
				if(j == 0){hit_vec->x = sign;}else{hit_vec->x = 0.f;}
				if(j == 1){hit_vec->y = sign;}else{hit_vec->y = 0.f;}
				if(j == 2){hit_vec->z = sign;}else{hit_vec->z = 0.f;}
				bestdist = multiplier;
				continue; // no need to check side cases :P
			}
		}
        ///
		float first_dist;
		char first_dir;
		float second_dist;
		char second_dir;
		for (int n = 0, y = 0; n <= 2; n++)
        {
			if (n != j)
            {
				float dist;
				if(offset[n] > 0){dist = offset[n] - 0.5f;}else{dist = offset[n] + 0.5f;}
				dist = dist / lookdir[n];
				if (y == 0) {
					first_dist = dist;
					first_dir = n;
				} else {
					if (dist < first_dist) {
						second_dist = first_dist;
						second_dir = first_dir;
						first_dist = dist;
						first_dir = n;
					} else {
						second_dist = dist;
						second_dir = n;
					}
				}
				y++;
			}
		}
        ///
		{
			if(first_dist > depth || (hit != -1 && first_dist > bestdist)){continue;}
			float pos[] = {start_pos[0] + (lookdir[0] * first_dist), start_pos[1] + (lookdir[1] * first_dist), start_pos[2] + (lookdir[2] * first_dist)};
			if ((first_dir == 0 || (pos[0] >= g.voxels[i].x - 0.5f && pos[0] <= g.voxels[i].x + 0.5f)) &&
				(first_dir == 1 || (pos[1] >= g.voxels[i].y - 0.5f && pos[1] <= g.voxels[i].y + 0.5f)) &&
				(first_dir == 2 || (pos[2] >= g.voxels[i].z - 0.5f && pos[2] <= g.voxels[i].z + 0.5f)))
            {
				hit = i;
				float sign;
				if(offset[first_dir] > 0.f){sign = -1.f;}else{sign = 1.f;}
				if(first_dir == 0){hit_vec->x = sign;}else{hit_vec->x = 0.f;}
				if(first_dir == 1){hit_vec->y = sign;}else{hit_vec->y = 0.f;}
				if(first_dir == 2){hit_vec->z = sign;}else{hit_vec->z = 0.f;}
				bestdist = first_dist;
				continue;
			}
		}
        ///
		{
			if (second_dist > depth || (hit != -1 && second_dist > bestdist)){continue;}
			float pos[] = {start_pos[0] + (lookdir[0] * second_dist), start_pos[1] + (lookdir[1] * second_dist), start_pos[2] + (lookdir[2] * second_dist)};
			if ((second_dir == 0 || (pos[0] >= g.voxels[i].x - 0.5f && pos[0] <= g.voxels[i].x + 0.5f)) &&
				(second_dir == 1 || (pos[1] >= g.voxels[i].y - 0.5f && pos[1] <= g.voxels[i].y + 0.5f)) &&
				(second_dir == 2 || (pos[2] >= g.voxels[i].z - 0.5f && pos[2] <= g.voxels[i].z + 0.5f)))
            {
				hit = i;
				float sign;
				if(offset[second_dir] > 0.f){sign = -1.f;}else{sign = 1.f;}
				if(second_dir == 0){hit_vec->x = sign;}else{hit_vec->x = 0.f;}
				if(second_dir == 1){hit_vec->y = sign;}else{hit_vec->y = 0.f;}
				if(second_dir == 2){hit_vec->z = sign;}else{hit_vec->z = 0.f;}
				bestdist = second_dist;
				continue;
			}
		}
	}
	return hit;
}
void traceViewPath(const uint face)
{
    g.pb.w = -1.f;
    vec rp = g.pb;
    lray = ray(&rp, RAY_DEPTH, ipp);
    if(lray > -1 && face == 1)
    {
        rp.x += g.voxels[lray].x;
        rp.y += g.voxels[lray].y;
        rp.z += g.voxels[lray].z;
        uint rpif = 1;
        for(int i = 0; i < g.num_voxels; i++)
        {
            if(g.voxels[i].w < 0.f){continue;}
            if(rp.x == g.voxels[i].x && rp.y == g.voxels[i].y && rp.z == g.voxels[i].z)
            {
                rpif = 0;
                break;
            }
        }
        if(rpif == 1)
        {
            g.pb   = rp;
            g.pb.w = 1.f;
        }
    }
}
int placeVoxel(const float repeat_delay)
{
    ptt = t+repeat_delay;

    if(g.pb.w == -1){return -1;} // place block invalid color (failed ray indication)

    for(uint i = 256; i < g.num_voxels; i++)
    {
        if(g.voxels[i].w < 0.f)
        {
            g.voxels[i] = g.pb;
            g.voxels[i].w = g.st;
            return i;
        }
    }
    if(g.num_voxels < max_voxels)
    {
        g.voxels[g.num_voxels] = g.pb;
        g.voxels[g.num_voxels].w = g.st;
        const int r = g.num_voxels;
        g.num_voxels++;
        return r;
    }
    return -2; // no space left
}
int placeVoxelArb(const vec v)
{
    uint free = -1;
    for(uint i = 256; i < g.num_voxels; i++)
    {
        if(free == -1 && g.voxels[i].w < 0.f){free = i;} // find first free slot (pre-emptive)
        if(g.voxels[i].x == v.x && g.voxels[i].y == v.y && g.voxels[i].z == v.z){return -1;} // already exists
    }
    if(free != -1)
    {
        g.voxels[free] = v;
        return free;
    }
    if(g.num_voxels < max_voxels)
    {
        g.voxels[g.num_voxels] = v;
        const int r = g.num_voxels;
        g.num_voxels++;
        return r;
    }
    return -2; // no space left
}
int forceVoxelArb(const vec v)
{
    uint free = -1;
    for(uint i = 256; i < g.num_voxels; i++)
    {
        if(free == -1 && g.voxels[i].w < 0.f){free = i;} // find first free slot (pre-emptive)
        if(g.voxels[i].x == v.x && g.voxels[i].y == v.y && g.voxels[i].z == v.z){free = i;break;} // already exists
    }
    if(free != -1)
    {
        g.voxels[free] = v;
        return free;
    }
    if(g.num_voxels < max_voxels)
    {
        g.voxels[g.num_voxels] = v;
        const int r = g.num_voxels;
        g.num_voxels++;
        return r;
    }
    return -2; // no space left
}
void rotatePointed(const float x, const float y, const float z, const uint type)
{
    if(sdif.x == 0.f && sdif.y == 0.f && sdif.z == 0.f){return;} // no selection
    // check pointed node is not within selection
    uint good = 1;
    //traceViewPath(0); // not here, because sometimes we want to inject a fake lray
    if(lray > -1)
    {
        float lx=0.f,ly=0.f,lz=0.f,hx=0.f,hy=0.f,hz=0.f;
        if(sp1o.x < sp2.x){lx=sp1o.x;hx=sp2.x;}else{lx=sp2.x;hx=sp1o.x;}
        if(sp1o.y < sp2.y){ly=sp1o.y;hy=sp2.y;}else{ly=sp2.y;hy=sp1o.y;}
        if(sp1o.z < sp2.z){lz=sp1o.z;hz=sp2.z;}else{lz=sp2.z;hz=sp1o.z;}
        if( g.voxels[lray].x >= lx && g.voxels[lray].x <= hx &&
            g.voxels[lray].y >= ly && g.voxels[lray].y <= hy &&
            g.voxels[lray].z >= lz && g.voxels[lray].z <= hz )
        {
            good = 0;
        }
    }
    if(good == 1)
    {
        // copy nodes to new position, from sp1o to g.voxels[lray]
        for(uint i = 0; i < g.num_voxels; i++)
        {
            if(g.voxels[i].w < 0.f){continue;}
            float lx=0.f,ly=0.f,lz=0.f,hx=0.f,hy=0.f,hz=0.f;
            if(sp1o.x < sp2.x){lx=sp1o.x;hx=sp2.x;}else{lx=sp2.x;hx=sp1o.x;}
            if(sp1o.y < sp2.y){ly=sp1o.y;hy=sp2.y;}else{ly=sp2.y;hy=sp1o.y;}
            if(sp1o.z < sp2.z){lz=sp1o.z;hz=sp2.z;}else{lz=sp2.z;hz=sp1o.z;}
            if( g.voxels[i].x >= lx && g.voxels[i].x <= hx &&
                g.voxels[i].y >= ly && g.voxels[i].y <= hy &&
                g.voxels[i].z >= lz && g.voxels[i].z <= hz )
            {
                if(type == 0)
                {
                    forceVoxelArb((vec){g.voxels[lray].x+((g.voxels[i].y-sp1o.y)*x),
                                        g.voxels[lray].y+((g.voxels[i].x-sp1o.x)*y),
                                        g.voxels[lray].z+((g.voxels[i].z-sp1o.z)*z),
                                        g.voxels[i].w});
                }
                else if(type == 1)
                {
                    forceVoxelArb((vec){g.voxels[lray].x+((g.voxels[i].y-sp1o.y)*x),
                                        g.voxels[lray].y+((g.voxels[i].z-sp1o.z)*z),
                                        g.voxels[lray].z+((g.voxels[i].x-sp1o.x)*y),
                                        g.voxels[i].w});
                }
                else if(type == 2)
                {
                    forceVoxelArb((vec){g.voxels[lray].x+((g.voxels[i].x-sp1o.x)*y),
                                        g.voxels[lray].y+((g.voxels[i].y-sp1o.y)*x),
                                        g.voxels[lray].z+((g.voxels[i].z-sp1o.z)*z),
                                        g.voxels[i].w});
                }
                else if(type == 3)
                {
                    forceVoxelArb((vec){g.voxels[lray].x+((g.voxels[i].x-sp1o.x)*y),
                                        g.voxels[lray].y+((g.voxels[i].z-sp1o.z)*z),
                                        g.voxels[lray].z+((g.voxels[i].y-sp1o.y)*x),
                                        g.voxels[i].w});
                }
                else if(type == 4)
                {
                    forceVoxelArb((vec){g.voxels[lray].x+((g.voxels[i].z-sp1o.z)*z),
                                        g.voxels[lray].y+((g.voxels[i].x-sp1o.x)*y),
                                        g.voxels[lray].z+((g.voxels[i].y-sp1o.y)*x),
                                        g.voxels[i].w});
                }
                else if(type == 5)
                {
                    forceVoxelArb((vec){g.voxels[lray].x+((g.voxels[i].z-sp1o.z)*z),
                                        g.voxels[lray].y+((g.voxels[i].y-sp1o.y)*x),
                                        g.voxels[lray].z+((g.voxels[i].x-sp1o.x)*y),
                                        g.voxels[i].w});
                }
            }
        }
    }
}
void rotatePointedIndex(const uint c)
{
    if(c ==  0){rotatePointed( 1.f,  1.f,  1.f, 0);} //
    if(c ==  1){rotatePointed(-1.f, -1.f, -1.f, 0);}
    if(c ==  2){rotatePointed( 1.f,  1.f, -1.f, 0);}
    if(c ==  3){rotatePointed(-1.f, -1.f,  1.f, 0);}
    if(c ==  4){rotatePointed( 1.f,  1.f,  1.f, 1);} //
    if(c ==  5){rotatePointed(-1.f, -1.f, -1.f, 1);}
    if(c ==  6){rotatePointed( 1.f,  1.f, -1.f, 1);}
    if(c ==  7){rotatePointed(-1.f, -1.f,  1.f, 1);}
    if(c ==  8){rotatePointed( 1.f,  1.f,  1.f, 2);} //
    if(c ==  9){rotatePointed(-1.f, -1.f, -1.f, 2);}
    if(c == 10){rotatePointed( 1.f,  1.f, -1.f, 2);}
    if(c == 11){rotatePointed(-1.f, -1.f,  1.f, 2);}
    if(c == 12){rotatePointed( 1.f,  1.f,  1.f, 3);} //
    if(c == 13){rotatePointed(-1.f, -1.f, -1.f, 3);}
    if(c == 14){rotatePointed( 1.f,  1.f, -1.f, 3);}
    if(c == 15){rotatePointed(-1.f, -1.f,  1.f, 3);}
    if(c == 16){rotatePointed( 1.f,  1.f,  1.f, 4);} //
    if(c == 17){rotatePointed(-1.f, -1.f, -1.f, 4);}
    if(c == 18){rotatePointed( 1.f,  1.f, -1.f, 4);}
    if(c == 19){rotatePointed(-1.f, -1.f,  1.f, 4);}
    if(c == 20){rotatePointed( 1.f,  1.f,  1.f, 5);} //
    if(c == 21){rotatePointed(-1.f, -1.f, -1.f, 5);}
    if(c == 22){rotatePointed( 1.f, -1.f,  1.f, 5);}
    if(c == 23){rotatePointed(-1.f,  1.f, -1.f, 5);}
}

//*************************************
// more utility functions
//*************************************
void printAttrib(SDL_GLattr attr, char* name)
{
    int i;
    SDL_GL_GetAttribute(attr, &i);
    printf("%s: %i\n", name, i);
}
SDL_Surface* SDL_RGBA32Surface(Uint32 w, Uint32 h)
{
    return SDL_CreateRGBSurfaceWithFormat(0, w, h, 32, SDL_PIXELFORMAT_RGBA32);
}
void drawHud();
void doPerspective()
{
    glViewport(0, 0, winw, winh);
    if(winw > 500 && winh > 460)
    {
        SDL_FreeSurface(sHud);
        sHud = SDL_RGBA32Surface(winw, winh);
        drawHud();
        hudmap = esLoadTextureA(winw, winh, sHud->pixels, 0);
    }
    ww = (float)winw;
    wh = (float)winh;
    mIdent(&projection);
    mPerspective(&projection, 60.0f, ww / wh, 0.1f, ddist);
    glUniformMatrix4fv(projection_id, 1, GL_FALSE, (float*)&projection.m[0][0]);
}
forceinline uint insideFrustum(const float x, const float y, const float z)
{
    const float xm = x+g.pp.x, ym = y+g.pp.y, zm = z+g.pp.z;
    return (xm*look_dir.x) + (ym*look_dir.y) + (zm*look_dir.z) > 0.f; // check the angle
}
SDL_Surface* surfaceFromData(const Uint32* data, Uint32 w, Uint32 h)
{
    SDL_Surface* s = SDL_CreateRGBSurfaceWithFormat(0, w, h, 32, SDL_PIXELFORMAT_RGBA32);
    memcpy(s->pixels, data, s->pitch*h);
    return s;
}
forceinline Uint32 getpixel(const SDL_Surface *surface, Uint32 x, Uint32 y)
{
    const Uint8 *p = (Uint8*)surface->pixels + y * surface->pitch + x * surface->format->BytesPerPixel;
    return *(Uint32*)p;
}
forceinline void setpixel(SDL_Surface *surface, Uint32 x, Uint32 y, Uint32 pix)
{
    const Uint8* pixel = (Uint8*)surface->pixels + (y * surface->pitch) + (x * surface->format->BytesPerPixel);
    *((Uint32*)pixel) = pix;
}
void replaceColour(SDL_Surface* surf, SDL_Rect r, Uint32 old_color, Uint32 new_color)
{
    const Uint32 max_y = r.y+r.h;
    const Uint32 max_x = r.x+r.w;
    for(Uint32 y = r.y; y < max_y; ++y)
        for(Uint32 x = r.x; x < max_x; ++x)
            if(getpixel(surf, x, y) == old_color){setpixel(surf, x, y, new_color);}
}

//*************************************
// Simple Font
//*************************************
int drawText(SDL_Surface* o, const char* s, Uint32 x, Uint32 y, Uint8 colour)
{
    static const Uint8 font_map[] = {255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,0,0,255,255,255,255,255,255,255,255,255,255,255,255,255,0,0,255,255,255,255,255,255,255,0,0,0,255,255,255,255,255,255,0,0,255,255,255,255,255,255,255,255,255,0,0,255,255,255,255,0,0,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,0,0,0,255,255,0,0,0,0,0,255,255,0,0,0,0,0,0,0,0,0,0,255,255,0,0,0,0,0,0,0,0,0,0,255,0,0,0,0,0,0,0,0,255,255,255,0,0,0,0,0,0,255,0,0,0,0,0,0,255,255,0,0,0,0,255,255,255,0,0,255,255,255,255,255,0,0,0,0,255,255,255,0,255,0,0,0,0,0,255,0,0,0,0,0,255,255,0,0,0,0,0,255,0,0,0,0,0,255,255,255,0,0,0,0,0,0,0,0,0,0,0,0,0,255,255,255,0,0,0,0,255,255,0,0,0,0,255,255,0,0,255,255,0,0,0,0,255,255,0,0,0,0,255,255,0,0,0,0,0,0,0,0,255,255,255,255,255,255,0,0,255,255,255,255,255,255,255,255,255,255,255,255,255,0,0,255,255,255,255,255,255,0,0,255,255,255,255,255,255,255,255,0,0,255,255,255,255,0,0,255,0,0,0,0,255,255,255,255,0,0,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,0,0,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,0,0,0,0,255,255,0,0,255,255,0,0,0,0,255,255,0,0,0,0,255,255,255,255,255,0,255,255,0,0,0,0,0,255,0,0,0,0,255,0,0,0,0,0,0,255,0,0,0,0,255,255,0,0,0,0,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,0,0,0,255,255,0,0,255,255,0,0,0,0,255,255,255,255,0,0,255,255,0,0,255,0,0,255,255,255,0,0,255,255,255,0,0,255,255,255,255,255,0,0,255,255,255,0,0,255,0,0,255,255,255,255,0,0,0,0,255,0,0,255,0,0,255,255,255,0,0,0,255,255,255,0,0,0,0,0,0,255,255,0,0,0,255,255,255,0,0,0,0,255,255,0,0,0,0,255,255,255,0,0,0,0,255,255,0,0,255,0,0,255,255,255,255,255,255,0,0,255,255,0,0,255,255,255,0,0,0,0,255,255,0,0,0,0,255,255,0,0,255,255,0,0,0,0,255,255,0,0,0,0,255,255,0,0,255,255,255,255,0,0,255,255,255,255,255,255,0,0,255,255,255,255,255,255,255,255,255,255,255,255,255,0,0,255,255,255,255,255,255,0,0,255,255,255,255,255,255,255,255,0,0,255,255,255,255,255,255,255,255,255,0,0,255,255,255,255,0,0,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,0,0,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,0,0,255,255,0,0,0,0,0,255,0,0,255,255,0,0,0,0,255,255,0,0,255,255,255,0,0,255,255,0,0,255,255,255,0,0,255,255,255,255,255,255,255,255,0,0,0,0,255,255,0,0,0,0,255,255,0,0,255,255,255,255,255,255,255,0,255,255,255,255,255,255,255,255,0,0,255,0,0,255,0,0,255,255,0,0,0,0,255,255,255,255,0,0,255,255,255,0,0,0,0,255,255,255,0,0,255,255,255,0,0,255,255,255,255,255,0,0,255,255,255,0,0,255,0,0,255,255,255,255,0,0,0,0,0,0,255,255,0,0,255,255,255,0,0,0,0,255,0,0,0,0,0,0,0,0,255,0,0,0,255,255,255,0,0,0,0,255,255,0,0,0,0,255,255,255,0,0,0,0,255,255,0,0,255,0,0,255,255,255,255,255,255,0,0,255,255,0,0,255,255,255,0,0,0,0,255,255,0,0,0,0,255,255,0,0,255,255,0,0,255,0,0,0,0,255,255,0,0,0,0,255,255,255,255,0,0,0,255,0,0,0,0,255,0,0,0,0,0,255,255,0,0,0,0,255,0,0,0,0,0,255,0,0,0,0,255,0,0,0,255,255,0,0,0,0,0,0,0,0,0,0,255,0,0,0,0,0,0,0,255,255,0,0,0,0,0,0,0,0,0,255,0,0,0,255,0,0,0,0,0,255,255,0,0,0,0,255,0,0,0,0,0,255,255,0,0,0,0,0,0,0,255,0,255,0,0,0,0,0,0,0,0,0,0,255,255,0,0,0,0,255,255,0,0,0,0,255,0,0,255,0,0,0,0,255,255,0,0,0,0,255,255,0,0,0,0,0,0,0,0,0,255,255,0,0,255,0,0,255,255,255,255,255,0,0,255,255,255,255,0,0,255,255,0,0,0,255,255,0,0,255,255,255,0,0,255,255,255,255,255,255,255,0,0,255,0,0,255,255,0,0,0,0,255,255,0,0,0,0,255,255,255,255,255,0,255,255,255,255,255,255,255,255,0,0,255,0,0,255,0,0,0,0,0,255,0,0,255,255,255,255,0,0,255,255,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,255,255,255,255,255,0,0,0,0,0,0,0,255,0,0,255,255,255,255,0,0,0,0,0,255,255,255,0,0,255,255,255,0,255,0,0,0,0,255,0,0,0,255,0,0,0,0,0,0,255,255,255,0,0,0,0,255,255,0,0,0,0,255,255,255,0,0,0,0,255,255,0,0,255,0,0,0,0,0,255,255,255,0,0,255,255,0,0,255,255,255,0,0,255,0,0,0,0,255,255,0,0,255,0,0,255,0,0,255,255,255,0,0,255,255,255,0,0,0,0,255,255,255,0,0,0,255,255,255,255,255,0,0,0,0,255,255,0,0,0,0,255,255,255,0,0,255,255,0,0,0,0,255,255,0,0,0,0,255,255,0,0,255,255,0,0,0,0,255,255,0,0,0,0,255,0,0,0,0,255,0,0,255,0,0,0,0,255,255,0,0,255,255,0,0,0,0,255,255,0,0,0,0,255,255,0,0,0,0,255,255,0,0,0,0,255,255,0,0,0,0,0,0,0,0,255,255,255,0,0,255,255,0,0,255,255,0,0,0,0,255,255,0,0,0,0,255,0,0,255,0,0,0,0,255,255,0,0,0,0,255,255,0,0,255,255,255,0,0,0,0,255,255,0,0,255,0,0,255,255,255,255,0,0,255,255,255,0,0,0,255,255,0,255,0,0,255,255,0,0,0,0,255,0,0,0,0,0,255,255,255,255,0,0,255,255,0,0,0,0,255,0,0,255,255,0,0,0,0,255,255,255,255,255,0,255,255,255,255,255,255,255,255,0,0,255,0,0,255,0,0,255,255,0,0,0,0,255,255,255,255,0,0,255,255,255,0,0,0,0,255,255,255,0,0,255,255,255,0,0,255,255,0,0,0,0,0,255,255,255,0,0,255,0,0,255,255,255,255,0,0,0,0,0,255,255,255,0,0,255,255,255,0,255,255,0,0,255,255,0,0,0,255,255,0,0,0,0,0,255,255,255,0,0,0,0,0,0,0,255,0,0,255,255,255,0,0,0,0,0,0,0,255,255,255,0,0,0,0,0,255,255,0,0,255,255,0,0,255,255,255,0,0,255,0,0,0,0,255,255,0,0,0,0,0,0,0,0,255,255,255,0,0,255,255,255,255,0,0,255,255,255,0,0,0,255,255,255,0,0,0,0,0,0,0,255,255,0,0,0,0,255,255,255,0,0,255,255,0,0,0,0,0,0,0,0,0,0,255,255,0,0,255,255,0,0,0,0,255,255,0,0,0,0,255,0,0,0,0,0,0,255,255,0,0,0,0,255,255,0,0,255,255,0,0,0,0,255,255,0,0,0,0,255,255,0,0,0,0,255,255,0,0,0,0,255,255,0,0,0,0,255,255,0,0,0,0,255,0,0,255,255,0,0,255,255,0,0,255,0,0,0,0,255,0,0,255,0,0,255,0,0,255,0,0,0,0,255,255,0,0,0,0,255,255,255,0,0,255,0,0,255,255,0,0,255,0,0,255,255,255,0,0,255,255,255,255,255,255,0,0,0,255,255,0,0,255,255,255,255,255,0,0,0,0,255,255,0,0,255,255,255,0,0,255,0,0,255,255,0,0,255,0,0,0,0,0,255,255,255,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,255,255,0,0,0,0,255,255,255,255,0,0,255,255,255,0,0,0,0,255,255,255,0,0,255,255,255,0,0,255,255,255,0,0,0,0,255,255,255,0,0,255,0,0,255,255,255,255,0,0,0,0,0,0,255,255,0,0,255,255,255,0,255,255,255,255,255,255,0,0,0,255,255,255,0,0,0,0,255,255,255,0,0,0,0,255,255,255,255,0,0,255,255,255,0,0,0,0,255,0,0,255,255,255,255,255,255,0,0,255,255,0,0,255,255,0,0,255,255,255,0,0,255,0,0,0,0,255,255,0,0,0,255,255,0,0,0,255,255,0,0,0,0,255,255,255,0,0,255,255,0,0,0,255,255,255,0,0,255,255,0,0,0,0,255,255,0,0,0,0,255,255,255,0,0,255,255,0,0,0,0,255,255,255,255,0,0,255,255,0,0,255,255,0,0,0,0,255,255,0,0,0,0,255,0,0,0,0,0,0,255,255,0,0,0,0,255,255,0,0,255,255,0,0,0,0,255,255,0,0,0,0,255,255,0,0,0,0,255,255,0,0,0,0,255,255,0,0,0,0,255,255,255,0,0,0,0,0,0,255,255,0,0,255,255,0,0,255,0,0,0,0,255,0,0,0,0,0,0,0,0,255,0,0,0,0,255,255,0,0,0,0,255,255,0,0,255,255,0,0,255,255,0,0,255,0,0,255,255,0,0,255,255,255,255,255,255,255,0,0,0,0,0,0,0,0,255,255,255,255,0,0,0,0,255,255,0,0,255,255,0,0,255,255,0,0,255,255,0,0,255,255,255,255,0,0,255,255,255,255,255,255,255,0,255,255,255,255,255,255,255,0,0,255,255,255,0,0,0,0,255,255,0,0,0,0,255,255,255,255,0,0,255,255,0,0,255,0,0,255,255,255,0,0,255,255,255,0,0,255,255,255,0,0,0,0,255,255,255,0,0,255,0,0,255,255,255,255,0,0,0,0,255,0,0,255,0,0,255,255,255,0,255,255,255,255,255,255,0,0,0,255,255,255,255,0,0,0,255,255,255,0,0,0,0,255,255,255,255,0,0,255,255,255,0,0,0,0,255,255,0,0,255,255,255,255,255,0,0,255,255,0,0,255,255,0,0,255,255,255,0,0,255,255,0,0,255,255,255,255,0,0,255,255,0,0,255,255,0,0,255,255,0,0,255,255,0,0,255,255,0,0,255,255,255,255,0,0,255,255,0,0,0,0,255,255,0,0,0,0,255,255,255,0,0,255,255,0,0,0,0,255,255,255,255,0,0,255,255,0,0,255,255,0,0,0,0,255,255,0,0,0,0,255,0,0,0,0,255,0,0,255,0,0,0,0,255,255,0,0,255,255,0,0,0,0,255,255,0,0,0,0,255,255,0,0,0,0,255,255,0,0,0,0,255,255,0,0,0,0,255,255,255,255,255,0,0,0,0,255,255,0,0,255,255,0,0,255,255,0,0,255,255,255,0,0,255,255,0,0,255,0,0,255,255,0,0,255,255,0,0,255,255,0,0,255,255,255,0,0,255,255,0,0,255,0,0,255,0,0,255,255,255,255,0,0,255,255,0,0,255,255,255,0,0,255,0,0,255,255,0,0,0,0,255,255,0,0,255,255,0,0,255,255,0,0,255,255,0,0,255,255,255,255,0,0,0,0,0,0,255,255,255,0,255,255,255,255,255,255,255,0,0,255,255,255,0,0,0,0,0,0,0,255,255,0,0,0,0,0,0,0,0,0,0,255,255,0,0,0,0,0,0,0,255,255,255,255,0,0,0,0,0,0,0,0,255,255,255,0,0,0,0,0,0,0,0,0,0,255,0,0,255,255,0,0,0,0,0,0,0,0,255,255,255,255,255,255,0,0,0,255,255,255,255,0,255,0,0,0,0,0,255,0,0,255,255,255,255,255,0,0,0,0,0,255,0,0,255,255,255,0,0,0,0,0,0,0,255,255,255,0,0,255,255,255,0,0,0,0,0,255,255,255,0,0,255,255,255,255,0,0,255,255,0,0,255,255,0,0,255,255,0,0,255,255,0,0,255,255,0,0,0,0,0,0,255,0,0,0,0,0,0,0,0,0,0,255,255,0,0,0,0,255,0,0,0,0,0,255,0,0,0,0,0,0,0,255,255,255,0,0,0,0,0,0,0,255,255,0,0,0,0,255,0,0,0,0,255,255,0,0,0,0,0,0,255,255,0,0,255,255,0,0,0,0,255,255,0,0,255,0,0,0,0,255,0,0,0,0,0,255,255,0,0,0,0,0,0,0,255,255,0,0,0,0,255,255,0,0,0,255,0,0,0,0,0,255,255,0,0,255,255,255,0,0,255,255,0,0,255,0,0,255,255,0,0,255,255,0,0,255,255,0,0,0,0,0,255,0,0,0,0,255,0,0,0,0,0,0,0,0,0,0,255,0,0,0,0,255,255,255,255,0,0,255,255,0,0,0,0,255,255,0,0,0,0,255,255,255,0,0,255,255,255,0,0,0,0,255,255,0,0,0,0,255,0,0,0,0,255,255,255,0,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,0,0,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,0,0,255,255,255,255,255,255,255,255,255,0,0,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,0,0,255,255,255,255,255,255,255,255,0,0,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,0,0,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,0,0,0,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,0,0,0,0,255,255,255,255,255,255,255,255,255,0,0,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,0,0,255,255,255,255,255,255,255,255,0,0,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,0,0,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255};
    static const Uint32 m = 1;
    static SDL_Surface* font_black = NULL;
    static SDL_Surface* font_white = NULL;
    static SDL_Surface* font_aqua = NULL;
    static SDL_Surface* font_gold = NULL;
    static SDL_Surface* font_cia = NULL;
    if(font_black == NULL)
    {
        font_black = SDL_RGBA32Surface(380, 11);
        for(int y = 0; y < font_black->h; y++)
        {
            for(int x = 0; x < font_black->w; x++)
            {
                const Uint8 c = font_map[(y*font_black->w)+x];
                setpixel(font_black, x, y, SDL_MapRGBA(font_black->format, c, c, c, 255-c));
            }
        }
        font_white = SDL_RGBA32Surface(380, 11);
        SDL_BlitSurface(font_black, &font_black->clip_rect, font_white, &font_white->clip_rect);
        replaceColour(font_white, font_white->clip_rect, 0xFF000000, 0xFFFFFFFF);
        font_aqua = SDL_RGBA32Surface(380, 11);
        SDL_BlitSurface(font_black, &font_black->clip_rect, font_aqua, &font_aqua->clip_rect);
        replaceColour(font_aqua, font_aqua->clip_rect, 0xFF000000, 0xFFFFFF00);
        font_gold = SDL_RGBA32Surface(380, 11);
        SDL_BlitSurface(font_black, &font_black->clip_rect, font_gold, &font_gold->clip_rect);
        replaceColour(font_gold, font_gold->clip_rect, 0xFF000000, 0xFF00BFFF);
        font_cia = SDL_RGBA32Surface(380, 11);
        SDL_BlitSurface(font_black, &font_black->clip_rect, font_cia, &font_cia->clip_rect);
        replaceColour(font_cia, font_cia->clip_rect, 0xFF000000, 0xFF97C920);
        // #20c997(0xFF97C920) #00FF41(0xFF41FF00) #61d97c(0xFF7CD961) #51d4e9(0xFFE9D451)
    }
    if(s[0] == '*' && s[1] == 'K') // signal cleanup
    {
        SDL_FreeSurface(font_black);
        SDL_FreeSurface(font_white);
        SDL_FreeSurface(font_aqua);
        SDL_FreeSurface(font_gold);
        SDL_FreeSurface(font_cia);
        font_black = NULL;
        return 0;
    }
    SDL_Surface* font = font_black;
    if(     colour == 1){font = font_white;}
    else if(colour == 2){font = font_aqua;}
    else if(colour == 3){font = font_gold;}
    else if(colour == 4){font = font_cia;}
    SDL_Rect dr = {x, y, 0, 0};
    const Uint32 len = strlen(s);
    for(Uint32 i = 0; i < len; i++)
    {
             if(s[i] == 'A'){SDL_BlitSurface(font, &(SDL_Rect){0,0,7,9}, o, &dr); dr.x += 7+m;}
        else if(s[i] == 'B'){SDL_BlitSurface(font, &(SDL_Rect){7,0,6,9}, o, &dr); dr.x += 6+m;}
        else if(s[i] == 'C'){SDL_BlitSurface(font, &(SDL_Rect){13,0,6,9}, o, &dr); dr.x += 6+m;}
        else if(s[i] == 'D'){SDL_BlitSurface(font, &(SDL_Rect){19,0,7,9}, o, &dr); dr.x += 7+m;}
        else if(s[i] == 'E'){SDL_BlitSurface(font, &(SDL_Rect){26,0,5,9}, o, &dr); dr.x += 5+m;}
        else if(s[i] == 'F'){SDL_BlitSurface(font, &(SDL_Rect){31,0,5,9}, o, &dr); dr.x += 5+m;}
        else if(s[i] == 'G'){SDL_BlitSurface(font, &(SDL_Rect){36,0,7,9}, o, &dr); dr.x += 7+m;}
        else if(s[i] == 'H'){SDL_BlitSurface(font, &(SDL_Rect){43,0,7,9}, o, &dr); dr.x += 7+m;}
        else if(s[i] == 'I'){SDL_BlitSurface(font, &(SDL_Rect){50,0,4,9}, o, &dr); dr.x += 4+m;}
        else if(s[i] == 'J'){SDL_BlitSurface(font, &(SDL_Rect){54,0,5,9}, o, &dr); dr.x += 5+m;}
        else if(s[i] == 'K'){SDL_BlitSurface(font, &(SDL_Rect){59,0,6,9}, o, &dr); dr.x += 6+m;}
        else if(s[i] == 'L'){SDL_BlitSurface(font, &(SDL_Rect){65,0,5,9}, o, &dr); dr.x += 5+m;}
        else if(s[i] == 'M'){SDL_BlitSurface(font, &(SDL_Rect){70,0,9,9}, o, &dr); dr.x += 9+m;}
        else if(s[i] == 'N'){SDL_BlitSurface(font, &(SDL_Rect){79,0,6,9}, o, &dr); dr.x += 6+m;}
        else if(s[i] == 'O'){SDL_BlitSurface(font, &(SDL_Rect){85,0,7,9}, o, &dr); dr.x += 7+m;}
        else if(s[i] == 'P'){SDL_BlitSurface(font, &(SDL_Rect){92,0,6,9}, o, &dr); dr.x += 6+m;}
        else if(s[i] == 'Q'){SDL_BlitSurface(font, &(SDL_Rect){98,0,7,11}, o, &dr); dr.x += 7+m;}
        else if(s[i] == 'R'){SDL_BlitSurface(font, &(SDL_Rect){105,0,7,9}, o, &dr); dr.x += 7+m;}
        else if(s[i] == 'S'){SDL_BlitSurface(font, &(SDL_Rect){112,0,6,9}, o, &dr); dr.x += 6+m;}
        else if(s[i] == 'T'){SDL_BlitSurface(font, &(SDL_Rect){118,0,6,9}, o, &dr); dr.x += 6+m;}
        else if(s[i] == 'U'){SDL_BlitSurface(font, &(SDL_Rect){124,0,7,9}, o, &dr); dr.x += 7+m;}
        else if(s[i] == 'V'){SDL_BlitSurface(font, &(SDL_Rect){131,0,6,9}, o, &dr); dr.x += 6+m;}
        else if(s[i] == 'W'){SDL_BlitSurface(font, &(SDL_Rect){137,0,10,9}, o, &dr); dr.x += 10+m;}
        else if(s[i] == 'X'){SDL_BlitSurface(font, &(SDL_Rect){147,0,6,9}, o, &dr); dr.x += 6+m;}
        else if(s[i] == 'Y'){SDL_BlitSurface(font, &(SDL_Rect){153,0,6,9}, o, &dr); dr.x += 6+m;}
        else if(s[i] == 'Z'){SDL_BlitSurface(font, &(SDL_Rect){159,0,6,9}, o, &dr); dr.x += 6+m;}
        else if(s[i] == 'a'){SDL_BlitSurface(font, &(SDL_Rect){165,0,6,9}, o, &dr); dr.x += 6+m;}
        else if(s[i] == 'b'){SDL_BlitSurface(font, &(SDL_Rect){171,0,6,9}, o, &dr); dr.x += 6+m;}
        else if(s[i] == 'c'){SDL_BlitSurface(font, &(SDL_Rect){177,0,5,9}, o, &dr); dr.x += 5+m;}
        else if(s[i] == 'd'){SDL_BlitSurface(font, &(SDL_Rect){182,0,6,9}, o, &dr); dr.x += 6+m;}
        else if(s[i] == 'e'){SDL_BlitSurface(font, &(SDL_Rect){188,0,6,9}, o, &dr); dr.x += 6+m;}
        else if(s[i] == 'f'){SDL_BlitSurface(font, &(SDL_Rect){194,0,4,9}, o, &dr); dr.x += 3+m;}
        else if(s[i] == 'g'){SDL_BlitSurface(font, &(SDL_Rect){198,0,6,11}, o, &dr); dr.x += 6+m;}
        else if(s[i] == 'h'){SDL_BlitSurface(font, &(SDL_Rect){204,0,6,9}, o, &dr); dr.x += 6+m;}
        else if(s[i] == 'i'){SDL_BlitSurface(font, &(SDL_Rect){210,0,2,9}, o, &dr); dr.x += 2+m;}
        else if(s[i] == 'j'){SDL_BlitSurface(font, &(SDL_Rect){212,0,3,11}, o, &dr); dr.x += 3+m;}
        else if(s[i] == 'k'){SDL_BlitSurface(font, &(SDL_Rect){215,0,6,9}, o, &dr); dr.x += 6+m;}
        else if(s[i] == 'l'){SDL_BlitSurface(font, &(SDL_Rect){221,0,2,9}, o, &dr); dr.x += 2+m;}
        else if(s[i] == 'm'){SDL_BlitSurface(font, &(SDL_Rect){223,0,10,9}, o, &dr); dr.x += 10+m;}
        else if(s[i] == 'n'){SDL_BlitSurface(font, &(SDL_Rect){233,0,6,9}, o, &dr); dr.x += 6+m;}
        else if(s[i] == 'o'){SDL_BlitSurface(font, &(SDL_Rect){239,0,6,9}, o, &dr); dr.x += 6+m;}
        else if(s[i] == 'p'){SDL_BlitSurface(font, &(SDL_Rect){245,0,6,11}, o, &dr); dr.x += 6+m;}
        else if(s[i] == 'q'){SDL_BlitSurface(font, &(SDL_Rect){251,0,6,11}, o, &dr); dr.x += 6+m;}
        else if(s[i] == 'r'){SDL_BlitSurface(font, &(SDL_Rect){257,0,4,9}, o, &dr); dr.x += 4+m;}
        else if(s[i] == 's'){SDL_BlitSurface(font, &(SDL_Rect){261,0,5,9}, o, &dr); dr.x += 5+m;}
        else if(s[i] == 't'){SDL_BlitSurface(font, &(SDL_Rect){266,0,4,9}, o, &dr); dr.x += 4+m;}
        else if(s[i] == 'u'){SDL_BlitSurface(font, &(SDL_Rect){270,0,6,9}, o, &dr); dr.x += 6+m;}
        else if(s[i] == 'v'){SDL_BlitSurface(font, &(SDL_Rect){276,0,6,9}, o, &dr); dr.x += 6+m;}
        else if(s[i] == 'w'){SDL_BlitSurface(font, &(SDL_Rect){282,0,8,9}, o, &dr); dr.x += 8+m;}
        else if(s[i] == 'x'){SDL_BlitSurface(font, &(SDL_Rect){290,0,6,9}, o, &dr); dr.x += 6+m;}
        else if(s[i] == 'y'){SDL_BlitSurface(font, &(SDL_Rect){296,0,6,11}, o, &dr); dr.x += 6+m;}
        else if(s[i] == 'z'){SDL_BlitSurface(font, &(SDL_Rect){302,0,5,9}, o, &dr); dr.x += 5+m;}
        else if(s[i] == '0'){SDL_BlitSurface(font, &(SDL_Rect){307,0,6,9}, o, &dr); dr.x += 6+m;}
        else if(s[i] == '1'){SDL_BlitSurface(font, &(SDL_Rect){313,0,4,9}, o, &dr); dr.x += 4+m;}
        else if(s[i] == '2'){SDL_BlitSurface(font, &(SDL_Rect){317,0,6,9}, o, &dr); dr.x += 6+m;}
        else if(s[i] == '3'){SDL_BlitSurface(font, &(SDL_Rect){323,0,6,9}, o, &dr); dr.x += 6+m;}
        else if(s[i] == '4'){SDL_BlitSurface(font, &(SDL_Rect){329,0,6,9}, o, &dr); dr.x += 6+m;}
        else if(s[i] == '5'){SDL_BlitSurface(font, &(SDL_Rect){335,0,6,9}, o, &dr); dr.x += 6+m;}
        else if(s[i] == '6'){SDL_BlitSurface(font, &(SDL_Rect){341,0,6,9}, o, &dr); dr.x += 6+m;}
        else if(s[i] == '7'){SDL_BlitSurface(font, &(SDL_Rect){347,0,6,9}, o, &dr); dr.x += 6+m;}
        else if(s[i] == '8'){SDL_BlitSurface(font, &(SDL_Rect){353,0,6,9}, o, &dr); dr.x += 6+m;}
        else if(s[i] == '9'){SDL_BlitSurface(font, &(SDL_Rect){359,0,6,9}, o, &dr); dr.x += 6+m;}
        else if(s[i] == ':'){SDL_BlitSurface(font, &(SDL_Rect){365,0,2,9}, o, &dr); dr.x += 2+m;}
        else if(s[i] == '.'){SDL_BlitSurface(font, &(SDL_Rect){367,0,2,9}, o, &dr); dr.x += 2+m;}
        else if(s[i] == '+'){SDL_BlitSurface(font, &(SDL_Rect){369,0,7,9}, o, &dr); dr.x += 7+m;}
        else if(s[i] == '-'){dr.x++; SDL_BlitSurface(font, &(SDL_Rect){376,0,4,9}, o, &dr); dr.x += 6+m;}
        else if(s[i] == ' '){dr.x += 2+m;}
    }
    return dr.x;
}

int lenText(const char* s)
{
    int x = 0;
    static const int m = 1;
    const Uint32 len = strlen(s);
    for(Uint32 i = 0; i < len; i++)
    {
             if(s[i] == 'A'){x += 7+m;}
        else if(s[i] == 'B'){x += 6+m;}
        else if(s[i] == 'C'){x += 6+m;}
        else if(s[i] == 'D'){x += 7+m;}
        else if(s[i] == 'E'){x += 5+m;}
        else if(s[i] == 'F'){x += 5+m;}
        else if(s[i] == 'G'){x += 7+m;}
        else if(s[i] == 'H'){x += 7+m;}
        else if(s[i] == 'I'){x += 4+m;}
        else if(s[i] == 'J'){x += 5+m;}
        else if(s[i] == 'K'){x += 6+m;}
        else if(s[i] == 'L'){x += 5+m;}
        else if(s[i] == 'M'){x += 9+m;}
        else if(s[i] == 'N'){x += 6+m;}
        else if(s[i] == 'O'){x += 7+m;}
        else if(s[i] == 'P'){x += 6+m;}
        else if(s[i] == 'Q'){x += 7+m;}
        else if(s[i] == 'R'){x += 7+m;}
        else if(s[i] == 'S'){x += 6+m;}
        else if(s[i] == 'T'){x += 6+m;}
        else if(s[i] == 'U'){x += 7+m;}
        else if(s[i] == 'V'){x += 6+m;}
        else if(s[i] == 'W'){x += 10+m;}
        else if(s[i] == 'X'){x += 6+m;}
        else if(s[i] == 'Y'){x += 6+m;}
        else if(s[i] == 'Z'){x += 6+m;}
        else if(s[i] == 'a'){x += 6+m;}
        else if(s[i] == 'b'){x += 6+m;}
        else if(s[i] == 'c'){x += 5+m;}
        else if(s[i] == 'd'){x += 6+m;}
        else if(s[i] == 'e'){x += 6+m;}
        else if(s[i] == 'f'){x += 3+m;}
        else if(s[i] == 'g'){x += 6+m;}
        else if(s[i] == 'h'){x += 6+m;}
        else if(s[i] == 'i'){x += 2+m;}
        else if(s[i] == 'j'){x += 3+m;}
        else if(s[i] == 'k'){x += 6+m;}
        else if(s[i] == 'l'){x += 2+m;}
        else if(s[i] == 'm'){x += 10+m;}
        else if(s[i] == 'n'){x += 6+m;}
        else if(s[i] == 'o'){x += 6+m;}
        else if(s[i] == 'p'){x += 6+m;}
        else if(s[i] == 'q'){x += 6+m;}
        else if(s[i] == 'r'){x += 4+m;}
        else if(s[i] == 's'){x += 5+m;}
        else if(s[i] == 't'){x += 4+m;}
        else if(s[i] == 'u'){x += 6+m;}
        else if(s[i] == 'v'){x += 6+m;}
        else if(s[i] == 'w'){x += 8+m;}
        else if(s[i] == 'x'){x += 6+m;}
        else if(s[i] == 'y'){x += 6+m;}
        else if(s[i] == 'z'){x += 5+m;}
        else if(s[i] == '0'){x += 6+m;}
        else if(s[i] == '1'){x += 4+m;}
        else if(s[i] == '2'){x += 6+m;}
        else if(s[i] == '3'){x += 6+m;}
        else if(s[i] == '4'){x += 6+m;}
        else if(s[i] == '5'){x += 6+m;}
        else if(s[i] == '6'){x += 6+m;}
        else if(s[i] == '7'){x += 6+m;}
        else if(s[i] == '8'){x += 6+m;}
        else if(s[i] == '9'){x += 6+m;}
        else if(s[i] == ':'){x += 2+m;}
        else if(s[i] == '.'){x += 2+m;}
        else if(s[i] == '+'){x += 7+m;}
        else if(s[i] == '-'){x += 7+m;}
        else if(s[i] == ' '){x += 2+m;}
    }
    return x;
}

//*************************************
// update & render
//*************************************
void main_loop()
{
//*************************************
// time delta for interpolation
//*************************************
    static float lt = 0;
    t = fTime();
    const float dt = t-lt;
    lt = t;

//*************************************
// input handling
//*************************************
    static int mx=0, my=0, lx=0, ly=0, md=0;
    static float idle = 0.f;

    // if user is idle for 3 minutes, save.
    if(idle != 0.f && t-idle > 180.f)
    {
        // char tmp[32];
        // tmp[0] = '.';
        // tmp[1] = 'i';
        // tmp[2] = 'd';
        // tmp[3] = 'l';
        // tmp[4] = 'e';
        // tmp[5] = '.';
        // const time_t tt = time(0);
        // strftime(&tmp[6], 32, "%d-%m-%y_%H:%M:%S", localtime(&tt));
        saveState(".idle");
        idle = 0.f; // so we only save once
        // on input a new idle is set, and a
        // count-down for a new save begins.
    }
    
    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
        switch(event.type)
        {
            case SDL_KEYDOWN:
            {
                if(focus_mouse == 0){break;}
                if(event.key.keysym.sym == SDLK_w){ks[0] = 1;}
                else if(event.key.keysym.sym == SDLK_a){ks[1] = 1;}
                else if(event.key.keysym.sym == SDLK_s){ks[2] = 1;}
                else if(event.key.keysym.sym == SDLK_d){ks[3] = 1;}
                else if(event.key.keysym.sym == SDLK_LSHIFT || event.key.keysym.sym == SDLK_LCTRL){ks[4] = 1;} // move down Z
                else if(event.key.keysym.sym == SDLK_LEFT){ks[5] = 1;}
                else if(event.key.keysym.sym == SDLK_RIGHT){ks[6] = 1;}
                else if(event.key.keysym.sym == SDLK_UP){ks[7] = 1;}
                else if(event.key.keysym.sym == SDLK_DOWN){ks[8] = 1;}
                else if(event.key.keysym.sym == SDLK_SPACE){ks[9] = 1;} // move up Z
                else if(event.key.keysym.sym == SDLK_ESCAPE) // unlock mouse focus
                {
                    focus_mouse = 0;
                    SDL_ShowCursor(1);
                }
                else if(event.key.keysym.sym == SDLK_q) // clone pointed voxel color
                {
                    if(ise == 0)
                    {
                        traceViewPath(0);
                        if(lray > -1){sp1 = g.voxels[lray];}else{sdif=(vec){0.f,0.f,0.f};}
                        //printf("DOWN: %.2f, %.2f, %.2f\n", g.voxels[lray].x, g.voxels[lray].y, g.voxels[lray].z);
                        ise = 1;
                    }
                }
                else if(event.key.keysym.sym == SDLK_SLASH || event.key.keysym.sym == SDLK_x) // - change selected node
                {
                    traceViewPath(0);
                    if(lray > 255)
                    {
                        g.st = g.voxels[lray].w - 1.f;
                        if(g.st < 0.f){g.st = 255.f;}
                        g.voxels[lray].w = g.st;

                        if(sdif.x != 0.f && sdif.y != 0.f && sdif.z != 0.f)
                        {
                            for(uint i = 256; i < g.num_voxels; i++)
                            {
                                if(g.voxels[i].w < 0.f){continue;}
                                float lx=0.f,ly=0.f,lz=0.f,hx=0.f,hy=0.f,hz=0.f;
                                if(sp1o.x < sp2.x){lx=sp1o.x;hx=sp2.x;}else{lx=sp2.x;hx=sp1o.x;}
                                if(sp1o.y < sp2.y){ly=sp1o.y;hy=sp2.y;}else{ly=sp2.y;hy=sp1o.y;}
                                if(sp1o.z < sp2.z){lz=sp1o.z;hz=sp2.z;}else{lz=sp2.z;hz=sp1o.z;}
                                if( g.voxels[i].x >= lx && g.voxels[i].x <= hx &&
                                    g.voxels[i].y >= ly && g.voxels[i].y <= hy &&
                                    g.voxels[i].z >= lz && g.voxels[i].z <= hz )
                                {
                                    g.voxels[i].w = g.st;
                                }
                            }
                        }
                    }
                    else
                    {
                        g.st -= 1.f;
                        if(g.st < 0.f){g.st = 255.f;}
                    }
                }
                else if(event.key.keysym.sym == SDLK_QUOTE || event.key.keysym.sym == SDLK_c) // + change selected node
                {
                    traceViewPath(0);
                    if(lray > 255)
                    {
                        g.st = g.voxels[lray].w + 1.f;
                        if(g.st > 255.f){g.st = 0.f;}
                        g.voxels[lray].w = g.st;

                        if(sdif.x != 0.f && sdif.y != 0.f && sdif.z != 0.f)
                        {
                            for(uint i = 256; i < g.num_voxels; i++)
                            {
                                if(g.voxels[i].w < 0.f){continue;}
                                float lx=0.f,ly=0.f,lz=0.f,hx=0.f,hy=0.f,hz=0.f;
                                if(sp1o.x < sp2.x){lx=sp1o.x;hx=sp2.x;}else{lx=sp2.x;hx=sp1o.x;}
                                if(sp1o.y < sp2.y){ly=sp1o.y;hy=sp2.y;}else{ly=sp2.y;hy=sp1o.y;}
                                if(sp1o.z < sp2.z){lz=sp1o.z;hz=sp2.z;}else{lz=sp2.z;hz=sp1o.z;}
                                if( g.voxels[i].x >= lx && g.voxels[i].x <= hx &&
                                    g.voxels[i].y >= ly && g.voxels[i].y <= hy &&
                                    g.voxels[i].z >= lz && g.voxels[i].z <= hz )
                                {
                                    g.voxels[i].w = g.st;
                                }
                            }
                        }
                    }
                    else
                    {
                        g.st += 1.f;
                        if(g.st > 255.f){g.st = 0.f;}
                    }
                }
                else if(event.key.keysym.sym == SDLK_RCTRL) // remove pointed voxel
                {
                    dtt = t+rrsp;
                    traceViewPath(0);
                    if(lray > 255)
                    {
                        g.voxels[lray].w = -1.f;
                        //optimState();
                    }
                }
                else if(event.key.keysym.sym == SDLK_RSHIFT) // place a voxel
                {
                    traceViewPath(1);
                    placeVoxel(rrsp);
                }
                else if(event.key.keysym.sym == SDLK_e) // replace pointed voxel
                {
                    rtt = t+rrsp;
                    traceViewPath(0);
                    if(lray > 255)
                    {
                        if(ise == 0)
                        {
                            if(sdif.x != 0.f && sdif.y != 0.f && sdif.z != 0.f)
                            {
                                for(uint i = 256; i < g.num_voxels; i++)
                                {
                                    if(g.voxels[i].w < 0.f){continue;}
                                    float lx=0.f,ly=0.f,lz=0.f,hx=0.f,hy=0.f,hz=0.f;
                                    if(sp1o.x < sp2.x){lx=sp1o.x;hx=sp2.x;}else{lx=sp2.x;hx=sp1o.x;}
                                    if(sp1o.y < sp2.y){ly=sp1o.y;hy=sp2.y;}else{ly=sp2.y;hy=sp1o.y;}
                                    if(sp1o.z < sp2.z){lz=sp1o.z;hz=sp2.z;}else{lz=sp2.z;hz=sp1o.z;}
                                    if( g.voxels[i].x >= lx && g.voxels[i].x <= hx &&
                                        g.voxels[i].y >= ly && g.voxels[i].y <= hy &&
                                        g.voxels[i].z >= lz && g.voxels[i].z <= hz )
                                    {
                                        g.voxels[i].w = g.st;
                                    }
                                }
                            }
                            else
                            {
                                g.voxels[lray].w = g.st;
                            }
                        }
                    }
                }
                else if(event.key.keysym.sym == SDLK_g) // gravity toggle
                {
                    g.grav = 1 - g.grav;
                }
                else if(event.key.keysym.sym == SDLK_f) // toggle movement speeds
                {
                    fks = 1 - fks;
                    if(fks){g.ms = g.cms;}
                       else{g.ms = g.lms;}
                }
                else if(event.key.keysym.sym == SDLK_1)
                {
                    g.ms = 9.3f;
                    if(fks){g.cms=g.ms;}else{g.lms=g.ms;}
                }
                else if(event.key.keysym.sym == SDLK_2)
                {
                    g.ms = 18.6f;
                    if(fks){g.cms=g.ms;}else{g.lms=g.ms;}
                }
                else if(event.key.keysym.sym == SDLK_3)
                {
                    g.ms = 37.2f;
                    if(fks){g.cms=g.ms;}else{g.lms=g.ms;}
                }
                else if(event.key.keysym.sym == SDLK_4)
                {
                    g.ms = 74.4f;
                    if(fks){g.cms=g.ms;}else{g.lms=g.ms;}
                }
                else if(event.key.keysym.sym == SDLK_5)
                {
                    g.ms = 148.8f;
                    if(fks){g.cms=g.ms;}else{g.lms=g.ms;}
                }
                else if(event.key.keysym.sym == SDLK_6)
                {
                    g.ms = 297.6f;
                    if(fks){g.cms=g.ms;}else{g.lms=g.ms;}
                }
                else if(event.key.keysym.sym == SDLK_7)
                {
                    g.ms = 595.2f;
                    if(fks){g.cms=g.ms;}else{g.lms=g.ms;}
                }
                else if(event.key.keysym.sym == SDLK_F1)
                {
                    defaultState(0);
                    fks = 0;
                }
                else if(event.key.keysym.sym == SDLK_TAB)
                {
                    static vec lp = (vec){0.f, 0.f, 0.f, -1.f};
                    static float rx,ry;
                    if(lp.w == -1)
                    {
                        lp = g.pp;
                        rx = g.xrot;
                        ry = g.yrot;
                        g.xrot = 0.f;
                        g.yrot = 1.57f;
                        g.pp = (vec){-8.f, 14.f, -8.f};
                    }
                    else
                    {
                        g.pp = lp;
                        g.xrot = rx;
                        g.yrot = ry;
                        lp = (vec){0.f, 0.f, 0.f, -1.f};
                    }
                }
                else if(event.key.keysym.sym == SDLK_b)
                {
                    if(sdif.x == 0.f && sdif.y == 0.f && sdif.z == 0.f){break;}

                    const float xinc = sdifo.x > 0.f ? 1.f : -1.f;
                    for(float x = sp1o.x; x != sp2.x+xinc; x += xinc)
                    {
                        const float yinc = sdifo.y > 0.f ? 1.f : -1.f;
                        for(float y = sp1o.y; y != sp2.y+yinc; y += yinc)
                        {
                            const float zinc = sdifo.z > 0.f ? 1.f : -1.f;
                            for(float z = sp1o.z; z != sp2.z+zinc; z += zinc)
                            {
                                uint df = 0;
                                for(uint i = 256; i < g.num_voxels; i++)
                                {
                                    if(g.voxels[i].x == x && g.voxels[i].y == y && g.voxels[i].z == z)
                                    {
                                        g.voxels[i].w = g.st;
                                        df=1;
                                    }
                                }
                                if(df == 0)
                                {
                                    uint df2 = 0;
                                    for(uint i = 256; i < g.num_voxels; i++)
                                    {
                                        if(g.voxels[i].w < 0.f)
                                        {
                                            g.voxels[i] = (vec){x,y,z,g.st};
                                            df2 = 1;
                                            break;
                                        }
                                    }
                                    if(df2 == 0 && g.num_voxels < max_voxels)
                                    {
                                        g.voxels[g.num_voxels] = (vec){x,y,z,g.st};
                                        const int r = g.num_voxels;
                                        g.num_voxels++;
                                    }
                                }
                            }
                        }
                    }
                }
                else if(event.key.keysym.sym == SDLK_r)
                {
                    vec p = g.pp;
                    vInv(&p);
                    vec pi = look_dir;
                    vMulS(&pi, pi, 6.f);
                    vAdd(&p, p, pi);
                    placeVoxelArb((vec){roundf(p.x), roundf(p.y), roundf(p.z), g.st});
                }
                else if(event.key.keysym.sym == SDLK_v)
                {
                    if(sdif.x == 0.f && sdif.y == 0.f && sdif.z == 0.f){break;} // no selection
                    // check pointed node is not within selection area
                    uint good = 1;
                    traceViewPath(0);
                    if(lray > -1)
                    {
                        float lx=0.f,ly=0.f,lz=0.f,hx=0.f,hy=0.f,hz=0.f;
                        if(sp1o.x < sp2.x){lx=sp1o.x;hx=sp2.x;}else{lx=sp2.x;hx=sp1o.x;}
                        if(sp1o.y < sp2.y){ly=sp1o.y;hy=sp2.y;}else{ly=sp2.y;hy=sp1o.y;}
                        if(sp1o.z < sp2.z){lz=sp1o.z;hz=sp2.z;}else{lz=sp2.z;hz=sp1o.z;}
                        if( g.voxels[lray].x >= lx && g.voxels[lray].x <= hx &&
                            g.voxels[lray].y >= ly && g.voxels[lray].y <= hy &&
                            g.voxels[lray].z >= lz && g.voxels[lray].z <= hz )
                        {
                            good = 0;
                        }
                    }else{good=0;}
                    if(good == 1)
                    {
                        // copy nodes to new position, from sp1o to g.voxels[lray]
                        for(uint i = 0; i < g.num_voxels; i++)
                        {
                            if(g.voxels[i].w < 0.f){continue;}
                            float lx=0.f,ly=0.f,lz=0.f,hx=0.f,hy=0.f,hz=0.f;
                            if(sp1o.x < sp2.x){lx=sp1o.x;hx=sp2.x;}else{lx=sp2.x;hx=sp1o.x;}
                            if(sp1o.y < sp2.y){ly=sp1o.y;hy=sp2.y;}else{ly=sp2.y;hy=sp1o.y;}
                            if(sp1o.z < sp2.z){lz=sp1o.z;hz=sp2.z;}else{lz=sp2.z;hz=sp1o.z;}
                            if( g.voxels[i].x >= lx && g.voxels[i].x <= hx &&
                                g.voxels[i].y >= ly && g.voxels[i].y <= hy &&
                                g.voxels[i].z >= lz && g.voxels[i].z <= hz )
                            {
                                forceVoxelArb((vec){g.voxels[lray].x+(g.voxels[i].x-sp1o.x),
                                                    g.voxels[lray].y+(g.voxels[i].y-sp1o.y),
                                                    g.voxels[lray].z+(g.voxels[i].z-sp1o.z),
                                                    g.voxels[i].w});
                            }
                        }
                    }
                }
                else if(event.key.keysym.sym == SDLK_n)
                {
                    if(sdif.x == 0.f && sdif.y == 0.f && sdif.z == 0.f){break;}
                    for(uint i = 256; i < g.num_voxels; i++)
                    {
                        if(g.voxels[i].w < 0.f){continue;}
                        float lx=0.f,ly=0.f,lz=0.f,hx=0.f,hy=0.f,hz=0.f;
                        if(sp1o.x < sp2.x){lx=sp1o.x;hx=sp2.x;}else{lx=sp2.x;hx=sp1o.x;}
                        if(sp1o.y < sp2.y){ly=sp1o.y;hy=sp2.y;}else{ly=sp2.y;hy=sp1o.y;}
                        if(sp1o.z < sp2.z){lz=sp1o.z;hz=sp2.z;}else{lz=sp2.z;hz=sp1o.z;}
                        if( g.voxels[i].x >= lx && g.voxels[i].x <= hx &&
                            g.voxels[i].y >= ly && g.voxels[i].y <= hy &&
                            g.voxels[i].z >= lz && g.voxels[i].z <= hz )
                        {
                            g.voxels[i].w = -1.f;
                        }
                    }
                }
                else if(event.key.keysym.sym == SDLK_t)
                {
                    if(sdif.x == 0.f && sdif.y == 0.f && sdif.z == 0.f){break;}
                    static uint c = 0;
                    traceViewPath(0);
                    if(lray > -1){rotatePointedIndex(c);}
                    c++;
                    if(c > 23){c = 0;}
                }
                else if(event.key.keysym.sym == SDLK_y)
                {
                    if(sdif.x == 0.f && sdif.y == 0.f && sdif.z == 0.f){break;}
                    vec p = g.pp;
                    vec pi = look_dir;
                    vMulS(&pi, pi, vSumAbs(sdif));
                    vInv(&pi);
                    for(uint i = 0; i < 24; i++)
                    {
                        vAdd(&p, p, pi);
                        lray = forceVoxelArb((vec){-p.x, -p.y, -p.z, g.st});
                        rotatePointedIndex(i);
                    }
                }
                else if(event.key.keysym.sym == SDLK_F3)
                {
                    saveState("");
                }
                else if(event.key.keysym.sym == SDLK_F8)
                {
                    loadState();
                }
#ifdef __linux__
                else if(event.key.keysym.sym == SDLK_F10) // export
                {
                    char tmp[32];
                    const time_t tt = time(0);
                    strftime(tmp, 32, "%d-%m-%y_%H:%M:%S", localtime(&tt));
                    char cmd[512];
                    sprintf(cmd, "%s/EXPORTS", getenv("HOME"));
                    mkdir(cmd, 0755);
                    sprintf(cmd, "%s/EXPORTS/VoxelPaintPro_exports", getenv("HOME"));
                    mkdir(cmd, 0755);
                    char tmp2[16];
                    timestamp(tmp2);
                    if(fileExist("/usr/bin/7z") == 1)
                    {
                        sprintf(cmd, "/usr/bin/7z a -y -bsp0 -bso0 -r %s/EXPORTS/VoxelPaintPro_exports/voxelpaintpro_%s_%u.7z %s/*", getenv("HOME"), tmp, g.num_voxels, appdir);
                        if(system(cmd) < 0){printf("system() failed: %s\n", cmd);}
                        printf("[%s] Exported data to: %s/EXPORTS/VoxelPaintPro_exports/voxelpaintpro_%s_%u.7z\n", tmp2, getenv("HOME"), tmp, g.num_voxels);
                    }
                    else if(fileExist("/usr/bin/zip") == 1)
                    {
                        sprintf(cmd, "/usr/bin/zip -jq9 %s/EXPORTS/VoxelPaintPro_exports/voxelpaintpro_%s_%u.zip %s/world.db %s/world.gz", getenv("HOME"), tmp, g.num_voxels, appdir, appdir);
                        if(system(cmd) < 0){printf("system() failed: %s\n", cmd);}
                        printf("[%s] Exported data to: %s/EXPORTS/VoxelPaintPro_exports/voxelpaintpro_%s_%u.zip\n", tmp2, getenv("HOME"), tmp, g.num_voxels);
                    }
                    else
                    {
                        printf("[%s] Unable to export. `/usr/bin/7z` or `/usr/bin/zip` could not be located.\n", tmp2);
                    }
                    
                }
#endif
#ifdef VERBOSE
                else if(event.key.keysym.sym == SDLK_p)
                {
                    for(int i = 0; i < 100000; i++)
                    {   // none of these voxels are grid-aligned without the roundf()
                        if(g.num_voxels >= max_voxels){break;}
                        g.voxels[g.num_voxels] = (vec){roundf(randfc()*ddist), roundf(randfc()*ddist), roundf(randfc()*ddist), esRand(0, 255)};
                        g.num_voxels++;
                    }
                }
#else
                else if(event.key.keysym.sym == SDLK_p)
                {
                    g.plock = 1 - g.plock;
                }
#endif
                idle = t;
            }
            break;

            case SDL_KEYUP:
            {
                if(focus_mouse == 0){break;}
                if(event.key.keysym.sym == SDLK_w){ks[0] = 0;}
                else if(event.key.keysym.sym == SDLK_a){ks[1] = 0;}
                else if(event.key.keysym.sym == SDLK_s){ks[2] = 0;}
                else if(event.key.keysym.sym == SDLK_d){ks[3] = 0;}
                else if(event.key.keysym.sym == SDLK_LSHIFT || event.key.keysym.sym == SDLK_LCTRL){ks[4] = 0;}
                else if(event.key.keysym.sym == SDLK_LEFT){ks[5] = 0;}
                else if(event.key.keysym.sym == SDLK_RIGHT){ks[6] = 0;}
                else if(event.key.keysym.sym == SDLK_UP){ks[7] = 0;}
                else if(event.key.keysym.sym == SDLK_DOWN){ks[8] = 0;}
                else if(event.key.keysym.sym == SDLK_SPACE){ks[9] = 0;}
                else if(event.key.keysym.sym == SDLK_RSHIFT){ptt = 0.f;}
                else if(event.key.keysym.sym == SDLK_RCTRL){dtt = 0.f;}
                else if(event.key.keysym.sym == SDLK_e){rtt = 0.f;}
                else if(event.key.keysym.sym == SDLK_q) // clone pointed voxel color
                {
                    traceViewPath(0);
                    if(lray > -1)
                    {
                        sp2 = g.voxels[lray];
                        if(sp1.x == sp2.x && sp1.y == sp2.y && sp1.z == sp2.z)
                        {
                            g.st = g.voxels[lray].w;
                            sdif=(vec){0.f,0.f,0.f};
                            ise = 0;
                        }
                        else
                        {
                            sp1o = sp1;
                            sp1d = sp1;
                            sdif = sp2;
                            vSub(&sdif, sdif, sp1);
                            sdifo = sdif;
                            if(sdif.x < 0.f){sp1d.x += 0.51f;sdif.x -= 1.02f;}else{sp1d.x -= 0.51f;sdif.x += 1.02f;}
                            if(sdif.y < 0.f){sp1d.y += 0.51f;sdif.y -= 1.02f;}else{sp1d.y -= 0.51f;sdif.y += 1.02f;}
                            if(sdif.z < 0.f){sp1d.z += 0.51f;sdif.z -= 1.02f;}else{sp1d.z -= 0.51f;sdif.z += 1.02f;}
                        }
                        //printf("UP: %.2f, %.2f, %.2f\n", g.voxels[lray].x, g.voxels[lray].y, g.voxels[lray].z);
                    }
                    ise = 0;
                }
                idle = t;
            }
            break;

            case SDL_MOUSEWHEEL: // change selected node
            {
                if(focus_mouse == 0){break;}

                bigc = t+0.5f;

                if(event.wheel.y > 0)
                {
                    g.st += 1.f;
                    if(g.st > 255.f){g.st = 0.f;}
                }
                else if(event.wheel.y < 0)
                {
                    g.st -= 1.f;
                    if(g.st < 0.f){g.st = 255.f;}
                }

                if(ise == 0)
                {
                    if(sdif.x != 0.f && sdif.y != 0.f && sdif.z != 0.f)
                    {
                        for(uint i = 256; i < g.num_voxels; i++)
                        {
                            if(g.voxels[i].w < 0.f){continue;}
                            float lx=0.f,ly=0.f,lz=0.f,hx=0.f,hy=0.f,hz=0.f;
                            if(sp1o.x < sp2.x){lx=sp1o.x;hx=sp2.x;}else{lx=sp2.x;hx=sp1o.x;}
                            if(sp1o.y < sp2.y){ly=sp1o.y;hy=sp2.y;}else{ly=sp2.y;hy=sp1o.y;}
                            if(sp1o.z < sp2.z){lz=sp1o.z;hz=sp2.z;}else{lz=sp2.z;hz=sp1o.z;}
                            if( g.voxels[i].x >= lx && g.voxels[i].x <= hx &&
                                g.voxels[i].y >= ly && g.voxels[i].y <= hy &&
                                g.voxels[i].z >= lz && g.voxels[i].z <= hz )
                            {
                                g.voxels[i].w = g.st;
                            }
                        }
                    }
                }
            }
            break;

            case SDL_MOUSEMOTION:
            {
                if(focus_mouse == 0){break;}
                mx = event.motion.x;
                my = event.motion.y;

                if(ise == 1)
                {
                    static float nt = 0.f;
                    if(t > nt)
                    {
                        traceViewPath(0);
                        if(lray > -1)
                        {
                            sp2 = g.voxels[lray];
                            if(sp1.x != sp2.x || sp1.y != sp2.y || sp1.z != sp2.z)
                            {
                                sp1o = sp1;
                                sp1d = sp1;
                                sdif = sp2;
                                vSub(&sdif, sdif, sp1);
                                sdifo = sdif;
                                if(sdif.x < 0.f){sp1d.x += 0.51f;sdif.x -= 1.02f;}else{sp1d.x -= 0.51f;sdif.x += 1.02f;}
                                if(sdif.y < 0.f){sp1d.y += 0.51f;sdif.y -= 1.02f;}else{sp1d.y -= 0.51f;sdif.y += 1.02f;}
                                if(sdif.z < 0.f){sp1d.z += 0.51f;sdif.z -= 1.02f;}else{sp1d.z -= 0.51f;sdif.z += 1.02f;}
                            }
                        }
                        nt = t+0.06f;
                    }
                }

                idle = t;
            }
            break;

            case SDL_MOUSEBUTTONUP:
            {
                if(event.button.button == SDL_BUTTON_LEFT){ptt = 0.f;}
                else if(event.button.button == SDL_BUTTON_RIGHT){dtt = 0.f;}
                else if(event.button.button == SDL_BUTTON_X2){rtt = 0.f;}
                else if(event.button.button == SDL_BUTTON_MIDDLE || event.button.button == SDL_BUTTON_X1) // clone pointed voxel
                {
                    traceViewPath(0);
                    if(lray > -1)
                    {
                        sp2 = g.voxels[lray];
                        if(sp1.x == sp2.x && sp1.y == sp2.y && sp1.z == sp2.z)
                        {
                            g.st = g.voxels[lray].w;
                            sdif=(vec){0.f,0.f,0.f};
                            ise = 0;
                            //bigc = t+0.25f;
                        }
                        else
                        {
                            sp1o = sp1;
                            sp1d = sp1;
                            sdif = sp2;
                            vSub(&sdif, sdif, sp1);
                            sdifo = sdif;
                            if(sdif.x < 0.f){sp1d.x += 0.51f;sdif.x -= 1.02f;}else{sp1d.x -= 0.51f;sdif.x += 1.02f;}
                            if(sdif.y < 0.f){sp1d.y += 0.51f;sdif.y -= 1.02f;}else{sp1d.y -= 0.51f;sdif.y += 1.02f;}
                            if(sdif.z < 0.f){sp1d.z += 0.51f;sdif.z -= 1.02f;}else{sp1d.z -= 0.51f;sdif.z += 1.02f;}
                        }
                        //printf("UP: %.2f, %.2f, %.2f\n", g.voxels[lray].x, g.voxels[lray].y, g.voxels[lray].z);
                    }
                    ise = 0;
                }
                md = 0;
                idle = t;
            }
            break;

            case SDL_MOUSEBUTTONDOWN:
            {
                lx = event.button.x;
                ly = event.button.y;
                mx = event.button.x;
                my = event.button.y;

                if(focus_mouse == 0) // lock mouse focus on every mouse input to the window
                {
                    SDL_ShowCursor(0);
                    focus_mouse = 1;
                    break;
                }

                if(event.button.button == SDL_BUTTON_LEFT) // place a voxel
                {
                    traceViewPath(1);
                    placeVoxel(rrsp);
                }
                else if(event.button.button == SDL_BUTTON_RIGHT) // remove pointed voxel
                {
                    dtt = t+rrsp;
                    traceViewPath(0);
                    if(lray > 255)
                    {
                        g.voxels[lray].w = -1.f;
                        //optimState();
                    }
                }
                else if(event.button.button == SDL_BUTTON_MIDDLE || event.button.button == SDL_BUTTON_X1) // clone pointed voxel
                {
                    traceViewPath(0);
                    if(lray > -1){sp1 = g.voxels[lray];}else{sdif=(vec){0.f,0.f,0.f};}
                    //printf("DOWN: %.2f, %.2f, %.2f\n", g.voxels[lray].x, g.voxels[lray].y, g.voxels[lray].z);
                    ise = 1;
                }
                else if(event.button.button == SDL_BUTTON_X2) // replace pointed node
                {
                    rtt = t+rrsp;
                    traceViewPath(0);
                    if(lray > 255)
                    {
                        if(ise == 0)
                        {
                            if(sdif.x != 0.f && sdif.y != 0.f && sdif.z != 0.f)
                            {
                                for(uint i = 256; i < g.num_voxels; i++)
                                {
                                    if(g.voxels[i].w < 0.f){continue;}
                                    float lx=0.f,ly=0.f,lz=0.f,hx=0.f,hy=0.f,hz=0.f;
                                    if(sp1o.x < sp2.x){lx=sp1o.x;hx=sp2.x;}else{lx=sp2.x;hx=sp1o.x;}
                                    if(sp1o.y < sp2.y){ly=sp1o.y;hy=sp2.y;}else{ly=sp2.y;hy=sp1o.y;}
                                    if(sp1o.z < sp2.z){lz=sp1o.z;hz=sp2.z;}else{lz=sp2.z;hz=sp1o.z;}
                                    if( g.voxels[i].x >= lx && g.voxels[i].x <= hx &&
                                        g.voxels[i].y >= ly && g.voxels[i].y <= hy &&
                                        g.voxels[i].z >= lz && g.voxels[i].z <= hz )
                                    {
                                        g.voxels[i].w = g.st;
                                    }
                                }
                            }
                            else
                            {
                                g.voxels[lray].w = g.st;
                            }
                        }
                    }
                }
                idle = t;
            }
            break;

            case SDL_WINDOWEVENT:
            {
                if(event.window.event == SDL_WINDOWEVENT_RESIZED)
                {
                    winw = event.window.data1;
                    winh = event.window.data2;
                    winw2 = winw/2;
                    winh2 = winh/2;
                    doPerspective();
                }
            }
            break;

            case SDL_QUIT:
            {
                SDL_HideWindow(wnd);
                saveState("");
                SDL_FreeSurface(s_icon);
                SDL_FreeSurface(sHud);
                SDL_GL_DeleteContext(glc);
                SDL_DestroyWindow(wnd);
                SDL_Quit();
                exit(0);
            }
            break;
        }
    }

//*************************************
// keystates
//*************************************
    if(focus_mouse == 1)
    {
        mGetViewZ(&look_dir, view);

        if(g.grav == 1 || g.plock == 1)
        {
            look_dir.z = -0.001f;
            vNorm(&look_dir);
        }

        if(ptt != 0.f && t > ptt) // place trigger
        {
            traceViewPath(1);
            placeVoxel(0.1f);
        }
        
        if(dtt != 0.f && t > dtt) // delete trigger
        {
            traceViewPath(0);
            if(lray > 255){g.voxels[lray].w = -1.f;}
            dtt = t+0.1f;
        }

        if(rtt != 0.f && t > rtt) // replace trigger
        {
            traceViewPath(0);
            if(lray > 255){g.voxels[lray].w = g.st;}
            rtt = t+0.1f;
        }

        if(ks[0] == 1) // W
        {
            vec m;
            vMulS(&m, look_dir, g.ms * dt);
            vSub(&g.pp, g.pp, m);
        }
        else if(ks[2] == 1) // S
        {
            vec m;
            vMulS(&m, look_dir, g.ms * dt);
            vAdd(&g.pp, g.pp, m);
        }

        if(ks[1] == 1) // A
        {
            vec vdc;
            mGetViewX(&vdc, view);
            vec m;
            vMulS(&m, vdc, g.ms * dt);
            vSub(&g.pp, g.pp, m);
        }
        else if(ks[3] == 1) // D
        {
            vec vdc;
            mGetViewX(&vdc, view);
            vec m;
            vMulS(&m, vdc, g.ms * dt);
            vAdd(&g.pp, g.pp, m);
        }

        if(ks[4] == 1) // LSHIFT (down)
        {
            vec vdc;
            if(g.plock == 1)
                vdc = (vec){0.f,0.f,-1.f};
            else
                mGetViewY(&vdc, view);
            vec m;
            vMulS(&m, vdc, g.ms * dt);
            vSub(&g.pp, g.pp, m);
        }
        else if(ks[9] == 1) // SPACE (up)
        {
            vec vdc;
            if(g.plock == 1)
                vdc = (vec){0.f,0.f,-1.f};
            else
                mGetViewY(&vdc, view);
            vec m;
            vMulS(&m, vdc, g.ms * dt);
            vAdd(&g.pp, g.pp, m);
        }

        if(ks[5] == 1) // LEFT
            g.xrot += 1.f*dt;
        else if(ks[6] == 1) // RIGHT
            g.xrot -= 1.f*dt;

        if(ks[7] == 1) // UP
            g.yrot += 1.f*dt;
        else if(ks[8] == 1) // DOWN
            g.yrot -= 1.f*dt;

        // player gravity
        if(g.grav == 1)
        {
            static uint falling = 0;

            vec vipp = g.pp; // inverse player position (setting global 'ipp' here is perfect)
            vInv(&vipp); // <--
            vipp.x = roundf(vipp.x);
            vipp.y = roundf(vipp.y);
            vipp.z = roundf(vipp.z); // now vipp is voxel aligned

            falling = 1;
            for(int j = 0; j < g.num_voxels; j++)
            {
                if(g.voxels[j].x == vipp.x && g.voxels[j].y == vipp.y && g.voxels[j].z == vipp.z-1.f)
                {
                    falling = 0;
                    break;
                }

                if(g.voxels[j].x == vipp.x && g.voxels[j].y == vipp.y && g.voxels[j].z == vipp.z-2.f)
                {
                    falling = 2;
                    break;
                }
            }
            // this extra loop makes you auto climb ALL nodes 
            for(int j = 0; j < g.num_voxels; j++)
            {
                if(g.voxels[j].x == vipp.x && g.voxels[j].y == vipp.y && g.voxels[j].z == vipp.z-1.f)
                {
                    falling = 0;
                    break;
                }
            }
            if(falling == 1)        {g.pp.z += (g.ms*0.5f)*dt;}
            else if(falling == 0)   {g.pp.z -= g.ms*dt;}

            mGetViewZ(&look_dir, view);
        }

    //*************************************
    // camera/mouse control
    //*************************************
        const float xd = lx-mx;
        const float yd = ly-my;
        if(xd != 0 || yd != 0)
        {
            g.xrot += xd*g.sens;
            g.yrot += yd*g.sens;

            if(g.plock == 1)
            {
                if(g.yrot > 3.11f)
                    g.yrot = 3.11f;
                if(g.yrot < 0.03f)
                    g.yrot = 0.03f;
            }
            else
            {
                if(g.yrot > 3.14f)
                    g.yrot = 3.14f;
                if(g.yrot < 0.1f)
                    g.yrot = 0.1f;
            }
            
            lx = winw2, ly = winh2;
            SDL_WarpMouseInWindow(wnd, lx, ly);
        }
    }

    mIdent(&view);
    mRotate(&view, g.yrot, 1.f, 0.f, 0.f);
    mRotate(&view, g.xrot, 0.f, 0.f, 1.f);
    mTranslate(&view, g.pp.x, g.pp.y, g.pp.z);

//*************************************
// begin render
//*************************************
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

//*************************************
// main render
//*************************************

    // voxels
    static uint sswi = 0;
    if(sswi == 0)
    {
        shadeVoxel(&projection_id, &view_id, &position_id, &normal_id, &voxel_id);
        glUniformMatrix4fv(projection_id, 1, GL_FALSE, (float*)&projection.m[0][0]);

        glBindBuffer(GL_ARRAY_BUFFER, mdlVoxel.vid);
        glVertexAttribPointer(position_id, 3, GL_FLOAT, GL_FALSE, 0, 0);
        glEnableVertexAttribArray(position_id);

        glBindBuffer(GL_ARRAY_BUFFER, mdlVoxel.nid);
        glVertexAttribPointer(normal_id, 3, GL_FLOAT, GL_FALSE, 0, 0);
        glEnableVertexAttribArray(normal_id);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mdlVoxel.iid);
        sswi = 1;
    }

    // render voxels
    ipp = g.pp; // inverse player position (setting global 'ipp' here is perfect)
    vInv(&ipp); // <--
    glUniformMatrix4fv(view_id, 1, GL_FALSE, (float*)&view.m[0][0]);
    mGetViewZ(&look_dir, view);
    for(int j = 0; j < g.num_voxels; j++)
    {
        if(g.voxels[j].w < 0.f || 
            vDistSq(ipp, g.voxels[j]) >= ddist2 ||
            insideFrustum(g.voxels[j].x, g.voxels[j].y, g.voxels[j].z) == 0){continue;}

        glUniform4f(voxel_id, g.voxels[j].x, g.voxels[j].y, g.voxels[j].z, g.voxels[j].w);
        glDrawElements(GL_TRIANGLES, voxel_numind, GL_UNSIGNED_BYTE, 0);
    }

    // render selection area
    if(sdif.x != 0.f && sdif.y != 0.f && sdif.z != 0.f)
    {
        glUniform4f(voxel_id, 0.f,0.f,0.f, 40.f);
        esRebind(GL_ARRAY_BUFFER, &mdlVoxel.vid, &(GLfloat[]){
                                                                sp1d.x, sp1d.y, sp1d.z,
                                                                sp1d.x+sdif.x, sp1d.y, sp1d.z,
                                                                sp1d.x+sdif.x, sp1d.y+sdif.y, sp1d.z,
                                                                sp1d.x, sp1d.y+sdif.y, sp1d.z,
                                                                //
                                                                sp1d.x, sp1d.y, sp1d.z+sdif.z,
                                                                sp1d.x+sdif.x, sp1d.y, sp1d.z+sdif.z,
                                                                sp1d.x+sdif.x, sp1d.y+sdif.y, sp1d.z+sdif.z,
                                                                sp1d.x, sp1d.y+sdif.y, sp1d.z+sdif.z,
                                                                sp1d.x, sp1d.y, sp1d.z+sdif.z,
                                                            }
                                                            , 10 * 3 * sizeof(float), GL_STATIC_DRAW);
        const vec v = (vec){-look_dir.x, -look_dir.y, -look_dir.z};
        esRebind(GL_ARRAY_BUFFER,         &mdlVoxel.nid, &(vec[]){v.x,v.y,v.z, v.x,v.y,v.z, v.x,v.y,v.z, v.x,v.y,v.z, v.x,v.y,v.z, v.x,v.y,v.z, v.x,v.y,v.z, v.x,v.y,v.z, v.x,v.y,v.z, v.x,v.y,v.z}, 10 * 3 * sizeof(float),  GL_STATIC_DRAW);
        esRebind(GL_ELEMENT_ARRAY_BUFFER, &mdlVoxel.iid, &(GLbyte[]){0,1,2,3,0,4,5,6,7,8,5,1,2,6,7,3}, 16,  GL_STATIC_DRAW); // could probably be reduced more
        glDrawElements(GL_LINE_STRIP, voxel_numind, GL_UNSIGNED_BYTE, 0);
        esRebind(GL_ARRAY_BUFFER,         &mdlVoxel.vid, voxel_vertices, sizeof(voxel_vertices), GL_STATIC_DRAW);
        esRebind(GL_ARRAY_BUFFER,         &mdlVoxel.nid, voxel_normals,  sizeof(voxel_normals),  GL_STATIC_DRAW);
        esRebind(GL_ELEMENT_ARRAY_BUFFER, &mdlVoxel.iid, voxel_indices,  sizeof(voxel_indices),  GL_STATIC_DRAW);
    }

    // crosshair
    mGetViewZ(&look_dir, view);
    float cdi = 130.f;
    if(t < bigc){cdi = 50.f;}
    const float nx = ipp.x+(look_dir.x*cdi), ny = ipp.y+(look_dir.y*cdi), nz = ipp.z+(look_dir.z*cdi);
    glUniform4f(voxel_id, nx, ny, nz, g.st);
    glDisable(GL_DEPTH_TEST);
        glDrawElements(GL_TRIANGLES, voxel_numind, GL_UNSIGNED_BYTE, 0);
    glEnable(GL_DEPTH_TEST);

    // hud
    if(focus_mouse == 0)
    {
        shadeHud(&position_id, &texcoord_id, &sampler_id);
        glUniformMatrix4fv(projection_id, 1, GL_FALSE, (float*)&projection.m[0][0]);
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, hudmap);
        glUniform1i(sampler_id, 0);
        glBindBuffer(GL_ARRAY_BUFFER, mdlPlane.vid);
        glVertexAttribPointer(position_id, 3, GL_FLOAT, GL_FALSE, 0, 0);
        glEnableVertexAttribArray(position_id);
        glBindBuffer(GL_ARRAY_BUFFER, mdlPlane.tid);
        glVertexAttribPointer(texcoord_id, 2, GL_FLOAT, GL_FALSE, 0, 0);
        glEnableVertexAttribArray(texcoord_id);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mdlPlane.iid);
        glDisable(GL_DEPTH_TEST);
        glEnable(GL_BLEND);
            glDrawElements(GL_TRIANGLES, hud_numind, GL_UNSIGNED_BYTE, 0);
        glDisable(GL_BLEND);
        glEnable(GL_DEPTH_TEST);
        sswi = 0;
    }

//*************************************
// swap buffers / display render
//*************************************
    SDL_GL_SwapWindow(wnd);
}
void drawHud()
{
    // clear cpu hud before rendering to it
    SDL_FillRect(sHud, &sHud->clip_rect, 0x00000000);
    // fps
    char tmp[16];
    sprintf(tmp, "%u", g_fps);
    SDL_FillRect(sHud, &(SDL_Rect){0, 0, lenText(tmp)+8, 19}, 0xCC000000);
    drawText(sHud, tmp, 4, 4, 2);
    // center hud
    const int top = winh2-(11*19);
    const int left = winw2-239;
    SDL_FillRect(sHud, &(SDL_Rect){winw2-253, top-3, 506, 432}, 0x33FFFFFF);
    SDL_FillRect(sHud, &(SDL_Rect){winw2-250, top, 500, 426}, 0xCC000000);
    int a = drawText(sHud, "Voxel Paint Pro", winw2-36, top+11, 3);
    a = drawText(sHud, appVersion, left+455, top+11, 4);
    a = drawText(sHud, "mrbid.github.io", left, top+11, 4);
    drawText(sHud, "Check console output for more information.", left, top+(11*3), 2);
    drawText(sHud, "The general idea is to use the Tab key to jump back and fourth to the 256 color", left, top+(11*5), 1);
    drawText(sHud, "palette when you need it. Just point at a color and press Q or Mouse4 or Middle Click", left, top+(11*6), 1);
    drawText(sHud, "to select that color. Also Q and E work great together, clone and replace single voxels.", left, top+(11*7), 1);
    a = drawText(sHud, "At any time when playing press ", left, top+(11*9), 1);
    a = drawText(sHud, "ESCAPE", a, top+(11*9), 3);
    drawText(sHud, " to release mouse focus back to this menu.", a, top+(11*9), 1);
    a = drawText(sHud, "This is the ", left, top+(11*11), 4);
    a = drawText(sHud, "256", a, top+(11*11), 2);
    a = drawText(sHud, " solid color version ", a, top+(11*11), 3);
    a = drawText(sHud, "using the ", a, top+(11*11), 4);
    a = drawText(sHud, "Aurora Palette", a, top+(11*11), 2);
    drawText(sHud, ".", a, top+(11*11), 4);

    a = drawText(sHud, "WASD ", left, top+(11*13), 2);
    drawText(sHud, "Move around based on relative orientation to X and Y.", a, top+(11*13), 1);
    
    a = drawText(sHud, "SPACE", left, top+(11*14), 2);
    a = drawText(sHud, " + ", a, top+(11*14), 4);
    a = drawText(sHud, "L-SHIFT ", a, top+(11*14), 2);
    drawText(sHud, "Move up and down relative Z.", a, top+(11*14), 1);

    a = drawText(sHud, "Left Click", left, top+(11*15), 2);
    a = drawText(sHud, " or ", a, top+(11*15), 3);
    a = drawText(sHud, "R-SHIFT ", a, top+(11*15), 2);
    drawText(sHud, "Place node.", a, top+(11*15), 1);

    a = drawText(sHud, "Right Click", left, top+(11*16), 2);
    a = drawText(sHud, " or ", a, top+(11*16), 3);
    a = drawText(sHud, "R-CTRL ", a, top+(11*16), 2);
    drawText(sHud, "Delete node.", a, top+(11*16), 1);

    a = drawText(sHud, "Tab ", left, top+(11*17), 2);
    drawText(sHud, "Teleports you to and from the colour palette.", a, top+(11*17), 1);

    a = drawText(sHud, "Q", left, top+(11*18), 2);
    a = drawText(sHud, " or ", a, top+(11*18), 3);
    a = drawText(sHud, "Middle Click", a, top+(11*18), 2);
    a = drawText(sHud, " or ", a, top+(11*18), 3);
    a = drawText(sHud, "Mouse4 ", a, top+(11*18), 2);
    drawText(sHud, "Clone color of pointed node.", a, top+(11*18), 1);

    a = drawText(sHud, "E", left, top+(11*19), 2);
    a = drawText(sHud, " or ", a, top+(11*19), 3);
    a = drawText(sHud, "Mouse5 ", a, top+(11*19), 2);
    drawText(sHud, "Replace pointed node.", a, top+(11*19), 1);

    a = drawText(sHud, "R ", left, top+(11*20), 2);
    drawText(sHud, "Places node at your current position.", a, top+(11*20), 1);

    a = drawText(sHud, "F ", left, top+(11*21), 2);
    drawText(sHud, "Toggle player fast speed on and off.", a, top+(11*21), 1);
    
    a = drawText(sHud, "1-7 ", left, top+(11*22), 2);
    drawText(sHud, "Change move speed for selected fast state.", a, top+(11*22), 1);
    
    a = drawText(sHud, "X", left, top+(11*23), 2);
    a = drawText(sHud, " + ", a, top+(11*23), 4);
    a = drawText(sHud, "C", a, top+(11*23), 2);
    a = drawText(sHud, " or ", a, top+(11*23), 3);
    a = drawText(sHud, "Slash", a, top+(11*23), 2);
    a = drawText(sHud, " + ", a, top+(11*23), 4);
    a = drawText(sHud, "Quote ", a, top+(11*23), 2);
    drawText(sHud, "Change color of pointed node.", a, top+(11*23), 1);
    
    a = drawText(sHud, "G ", left, top+(11*24), 2);
    drawText(sHud, "Toggle gravity on and off.", a, top+(11*24), 1);

    a = drawText(sHud, "P ", left, top+(11*25), 2);
    drawText(sHud, "Toggle pitch lock.", a, top+(11*25), 1);

    a = drawText(sHud, "F1 ", left, top+(11*26), 2);
    drawText(sHud, "Resets environment state back to default.", a, top+(11*26), 1);

    a = drawText(sHud, "F3 ", left, top+(11*27), 2);
    drawText(sHud, "Save. Will auto save on exit. Backup made if idle for 3 mins.", a, top+(11*27), 1);

    a = drawText(sHud, "F8 ", left, top+(11*28), 2);
    drawText(sHud, "Load. Will erase what you have done since the last save.", a, top+(11*28), 1);

    a = drawText(sHud, "V ", left, top+(11*30), 2);
    a = drawText(sHud, "Copies the selected nodes to the currently pointed position, the point you started", a, top+(11*30), 1);
    a = drawText(sHud, "    the selection from is the point you will copy from at the new pointed location.", left, top+(11*31), 1);

    a = drawText(sHud, "T ", left, top+(11*32), 2);
    a = drawText(sHud, "Copies the selected nodes to the currently pointed position, but each time you", a, top+(11*32), 1);
    drawText(sHud, "    press T it will iterate one of 24 rotations.", left, top+(11*33), 1);

    a = drawText(sHud, "Y ", left, top+(11*34), 2);
    a = drawText(sHud, "Shoots an array of the selected nodes in the direction you are facing in 24 different", a, top+(11*34), 1);
    drawText(sHud, "    rotations. Pick the one you want.", left, top+(11*35), 1);

    a = drawText(sHud, "B ", left, top+(11*36), 2);
    a = drawText(sHud, "Fill selected nodes with selected color.", a, top+(11*36), 1);

    a = drawText(sHud, "N ", left, top+(11*37), 2);
    a = drawText(sHud, "Delete selected nodes.", a, top+(11*37), 1);

    // flip the new hud to gpu
    flipHud();
}

//*************************************
// Process Entry Point
//*************************************
int main(int argc, char** argv)
{
//*************************************
// setup render context / window
//*************************************
    if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_EVENTS) < 0)
    {
        printf("ERROR: SDL_Init(): %s\n", SDL_GetError());
        return 1;
    }
    int msaa = 16;
    if(msaa > 0)
    {
        SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
        SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, msaa);
    }
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_ES);
    wnd = SDL_CreateWindow(appTitle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, winw, winh, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
    while(wnd == NULL)
    {
        if(msaa == 0)
        {
            printf("ERROR: SDL_CreateWindow(): %s\n", SDL_GetError());
            return 1;
        }
        SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, msaa/2);
        wnd = SDL_CreateWindow(appTitle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, winw, winh, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
    }
    SDL_GL_SetSwapInterval(1);
    glc = SDL_GL_CreateContext(wnd);
    if(glc == NULL)
    {
        printf("ERROR: SDL_GL_CreateContext(): %s\n", SDL_GetError());
        return 1;
    }

    // set icon
    s_icon = surfaceFromData((Uint32*)&icon, 16, 16);
    SDL_SetWindowIcon(wnd, s_icon);

    // seed random
    srand(time(0));
    srandf(time(0));

    // get paths
    basedir = SDL_GetBasePath();
    appdir = SDL_GetPrefPath("voxdsp", "voxelpaintpro");

    // print info
    printf("----\n");
    printAttrib(SDL_GL_DOUBLEBUFFER, "GL_DOUBLEBUFFER");
    printAttrib(SDL_GL_DEPTH_SIZE, "GL_DEPTH_SIZE");
    printAttrib(SDL_GL_RED_SIZE, "GL_RED_SIZE");
    printAttrib(SDL_GL_GREEN_SIZE, "GL_GREEN_SIZE");
    printAttrib(SDL_GL_BLUE_SIZE, "GL_BLUE_SIZE");
    printAttrib(SDL_GL_ALPHA_SIZE, "GL_ALPHA_SIZE");
    printAttrib(SDL_GL_BUFFER_SIZE, "GL_BUFFER_SIZE");
    printAttrib(SDL_GL_DOUBLEBUFFER, "GL_DOUBLEBUFFER");
    printAttrib(SDL_GL_DEPTH_SIZE, "GL_DEPTH_SIZE");
    printAttrib(SDL_GL_STENCIL_SIZE, "GL_STENCIL_SIZE");
    printAttrib(SDL_GL_ACCUM_RED_SIZE, "GL_ACCUM_RED_SIZE");
    printAttrib(SDL_GL_ACCUM_GREEN_SIZE, "GL_ACCUM_GREEN_SIZE");
    printAttrib(SDL_GL_ACCUM_BLUE_SIZE, "GL_ACCUM_BLUE_SIZE");
    printAttrib(SDL_GL_ACCUM_ALPHA_SIZE, "GL_ACCUM_ALPHA_SIZE");
    printAttrib(SDL_GL_STEREO, "GL_STEREO");
    printAttrib(SDL_GL_MULTISAMPLEBUFFERS, "GL_MULTISAMPLEBUFFERS");
    printAttrib(SDL_GL_MULTISAMPLESAMPLES, "GL_MULTISAMPLESAMPLES");
    printAttrib(SDL_GL_ACCELERATED_VISUAL, "GL_ACCELERATED_VISUAL");
    printAttrib(SDL_GL_RETAINED_BACKING, "GL_RETAINED_BACKING");
    printAttrib(SDL_GL_CONTEXT_MAJOR_VERSION, "GL_CONTEXT_MAJOR_VERSION");
    printAttrib(SDL_GL_CONTEXT_MINOR_VERSION, "GL_CONTEXT_MINOR_VERSION");
    printAttrib(SDL_GL_CONTEXT_FLAGS, "GL_CONTEXT_FLAGS");
    printAttrib(SDL_GL_CONTEXT_PROFILE_MASK, "GL_CONTEXT_PROFILE_MASK");
    printAttrib(SDL_GL_SHARE_WITH_CURRENT_CONTEXT, "GL_SHARE_WITH_CURRENT_CONTEXT");
    printAttrib(SDL_GL_FRAMEBUFFER_SRGB_CAPABLE, "GL_FRAMEBUFFER_SRGB_CAPABLE");
    printAttrib(SDL_GL_CONTEXT_RELEASE_BEHAVIOR, "GL_CONTEXT_RELEASE_BEHAVIOR");
    printAttrib(SDL_GL_CONTEXT_EGL, "GL_CONTEXT_EGL");
    printf("----\n");
    SDL_version compiled;
    SDL_version linked;
    SDL_VERSION(&compiled);
    SDL_GetVersion(&linked);
    printf("Compiled against SDL version %u.%u.%u.\n", compiled.major, compiled.minor, compiled.patch);
    printf("Linked against SDL version %u.%u.%u.\n", linked.major, linked.minor, linked.patch);
    printf("----\n");
    printf("currentPath: %s\n", basedir);
    printf("dataPath:    %s\n", appdir);
    printf("exportPath:  %s/EXPORTS/VoxelPaintPro_exports/\n", getenv("HOME"));
    printf("----\n");
    printf(">>> Voxel Paint Pro <<<\n");
    printf("----\n");
    printf("James William Fletcher (github.com/mrbid)\n");
    printf("----\n\n");
    printf("Mouse locks when you click on the game window, press ESCAPE to unlock the mouse.\n\n");
    printf("- Input Mapping\n");
    printf("W,A,S,D = Move around based on relative orientation to X and Y.\n");
    printf("SPACE + L-SHIFT = Move up and down relative Z.\n");
    printf("Left Click / R-SHIFT = Place node.\n");
    printf("Right Click / R-CTRL = Delete node.\n");
    printf("Tab = Teleports you from colour palette to last position and vice-versa.\n");
    printf("Q / Middle Click / Mouse4 = Clone color of pointed node.\n");
    printf("E / Mouse5 = Replace pointed node.\n");
    printf("R = Places node at your current position.\n");
    printf("F = Toggle player fast speed on and off.\n");
    printf("1-7 = Change move speed for selected fast state.\n");
    printf("X + C / Slash + Quote = Change color of pointed node.\n");
    printf("G = Gravity on/off.\n");
    printf("P = Toggle pitch lock.\n");
    printf("F1 = Resets environment state back to default.\n");
    printf("F3 = Save. (auto saves on exit, backup made if idle for 3 mins.)\n");
    printf("F8 = Load. (will erase what you have done since the last save)\n");
#ifdef __linux__
    printf("F10 = Export the VoxelPaint data to a zip file in $HOME/EXPORTS.\n");
#endif
    printf("\n- Multi Selections\n");
    printf("--------------------------------------------------------------------------\n");
    printf("Middle Mouse Click & Drag or Mouse4 & Drag (or Q and drag) to select area.\n");
    printf("--------------------------------------------------------------------------\n");
    printf("V = Copies the selected nodes to the currently pointed position,\n    the point you started the selection from is the point you will\n    copy from at the new pointed location.\n");
    printf("T = Copies the selected nodes to the currently pointed position,\n    but each time you press T it will iterate one of 24 rotations.\n");
    printf("Y = Shoots an array of the selected nodes in the direction you are\n    facing in 24 different rotations. Pick the one you want.\n");
    printf("B = Fill selected nodes with selected color.\nN = Delete selected nodes.\n");
    printf("--------------------------------------------\n");
    printf("\n* Arrow Keys can be used to move the view around.\n");
    printf("* Your state is automatically saved on exit.\n");
    printf("* You can change the mouse sensitivity by passing the new\n  sensitivity as the 1st command line parameter default is\n  0.003 `./vox 0.003`.\n");
    printf("* This uses the Aurora 256 Color Palette (https://lospec.com/palette-list/aurora).\n");
    printf("\n----\n");

//*************************************
// projection & compile & link shader program
//*************************************
    doPerspective();
    makeVoxel();
    makeHud();

//*************************************
// configure render options
//*************************************
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);
    glLineWidth(4.f);
#ifdef SKYBLUE
    glClearColor(0.3f, 0.745f, 0.8863f, 0.f);
#else
    glClearColor(0.f, 0.f, 0.f, 0.f);
#endif

//*************************************
// init stuff
//*************************************

    // color palette voxels
    memset(g.voxels, 0x00, sizeof(vec)*max_voxels);
    float si = 0.f;
    float sh = 0.f;
    for(uint i = 0; i < 256; i++)
    {
        const float fi = (float)i;
        g.voxels[i] = (vec){si, 0.f, sh, fi};
        si += 1.f;
        if(si >= 16.f){si = 0.f;sh += 1.f;}
    }
    g.num_voxels = 256;

    // load states
#ifdef NO_COMPRESSION
    if(loadState() == 0)
#else
    if(loadState() == 0 && loadUncompressedState() == 0)
#endif
    {
        // default state
        defaultState(0);

        // done
        char tmp[16];
        timestamp(tmp);
        printf("[%s] New world created.\n", tmp);
    }
    if(g.num_voxels == 0){g.num_voxels = 256;}

    // argv mouse sensitivity
    if(argc >= 2){g.sens = atof(argv[1]);}

    // make sure voxel data is grid-aligned
    if(argc == 3)
    {
        for(int i = 0; i < g.num_voxels; i++)
        {
            if(g.voxels[i].w < 0.f){continue;}
            g.voxels[i].x = roundf(g.voxels[i].x);
            g.voxels[i].y = roundf(g.voxels[i].y);
            g.voxels[i].z = roundf(g.voxels[i].z);
        }
    }

    // hud buffer
    sHud = SDL_RGBA32Surface(winw, winh);
    drawHud();
    hudmap = esLoadTextureA(winw, winh, sHud->pixels, 0);

//*************************************
// execute update / render loop
//*************************************
    t = fTime();
    uint fps = 0;
    float ft = t+3.f;
    while(1)
    {
        if(t > ft)
        {
            g_fps = fps/3;
#ifdef VERBOSE
            char tmp[16];
            timestamp(tmp);
            printf("[%s] %u fps, %u voxels\n", tmp, g_fps, g.num_voxels);
#endif
            if(focus_mouse == 0 && winw > 500 && winh > 460)
                drawHud();
            fps = 0;
            ft = t+3.f;
        }
        main_loop();
        fps++;
    }
    return 0;
}
