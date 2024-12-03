const std = @import("std");

fn prefixo(s1: []const u8, s2: []const u8) bool {
    if (s1.len > s2.len) return false;
    return std.mem.eql(u8, s1, s2[0..s1.len]);
}

fn sufixo(s1: []const u8, s2: []const u8) bool {
    if (s1.len > s2.len) return false;
    return std.mem.eql(u8, s1, s2[s2.len - s1.len..s2.len]);
}

fn subpalavra(s1: []const u8, s2: []const u8) bool {
    return std.mem.indexOf(u8, s2, s1) != null;
}

fn concatenacao(s1: []const u8, s2: []const u8) ![]const u8 {
    var allocator = std.heap.page_allocator;
    var buffer = try allocator.alloc(u8, s1.len + s2.len);
    defer allocator.free(buffer);

    std.mem.copy(u8, buffer[0..s1.len], s1);
    std.mem.copy(u8, buffer[s1.len..], s2);

    return buffer;
}

pub fn main() !void {
    const s1 = "hello";
    const s2 = "hello world";

    std.debug.print("Prefixo: {}\n", .{prefixo(s1, s2)});
    std.debug.print("Sufixo: {}\n", .{sufixo(s1, s2)});
    std.debug.print("Subpalavra: {}\n", .{subpalavra(s1, s2)});

    const s3 = try concatenacao(s1, s2);
    std.debug.print("Concatenação: {s}\n", .{s3});
}

test "funções de string" {
    const s1 = "hello";
    const s2 = "hello world";
    try std.testing.expect(prefixo(s1, s2) == true);
    try std.testing.expect(sufixo(s1, s2) == false);
    try std.testing.expect(subpalavra(s1, s2) == true);

    const s3 = try concatenacao(s1, s2);
    try std.testing.expect(std.mem.eql(u8, s3, "hellohello world"));
}

