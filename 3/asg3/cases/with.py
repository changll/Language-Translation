
def main(args = None):
    if args[0] == '-t':
        if len(args) != 2:
            print USAGE
            sys.exit(1)
        zf = ZipFile(args[1], 'r')
        badfile = zf.testzip()
        if badfile:
            print("The following enclosed file is corrupted: {!r}".format(badfile))
        print "Done testing"

    elif args[0] == '-e':
        if len(args) != 3:
            print USAGE
            sys.exit(1)

        zf = ZipFile(args[1], 'r')
        out = args[2]
        for path in zf.namelist():
            if path.startswith('./'):
                tgt = os.path.join(out, path[2:])
            else:
                tgt = os.path.join(out, path)

            tgtdir = os.path.dirname(tgt)
            with open(tgt, 'wb') as fp:
                fp.write(zf.read(path))
        zf.close()

    elif args[0] == '-c':
        if len(args) < 3:
            print USAGE
            sys.exit(1)

main()
